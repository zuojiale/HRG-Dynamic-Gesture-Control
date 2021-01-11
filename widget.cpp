#include "widget.h"
#include "ui_widget.h"

#include <torch/script.h>
#include <torch/torch.h>

#include <opencv/cv.hpp>
#include <opencv2/opencv.hpp>

#include <iostream>
#include <vector>
#include <stdio.h>

#include <QMessageBox>
#include <QFileDialog>
#include <QtConcurrent>
#include <QFuture>
#include <QInputDialog>
#include <QShortcut>

extern "C++"
{
    #include "HrgTofApi.h"
    #include <helper.h>
    #include "setparam.h"  //连接子窗口
    #include "connectthread.h" //多线程
    #include "handfinder.h"
    #include "mp3.h"
}

/********************************************************
 * function:Widget()
 * author:Zuo jiale
 * Date:2021-1-4
 * description:软件界面的构造函数，实现软件界面的初始化以及槽函数的设置
 * Params:输入None
 *        输出None
 * ****************************************************/
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    handfinder = new HandFinder;
    //1.界面初始化
    this->setFixedSize(849,478);//设置窗口固定大小为754*480
    //2.设置窗口名称
    this->setWindowTitle("HRG手势识别");
    //3.设置lcd显示风格
    ui->lcdPredict->setSegmentStyle(QLCDNumber::Outline);

    //4.显示HRG logo
    InitApp();
    //5.导入训练模型
    InitModel();
    //6.设置部分按钮变灰，因为未连接相机
    ui->buttonDisconnect->setEnabled(false);
    ui->buttonSave->setEnabled(false);
    ui->horizonFPS->setEnabled(false);
    //7.给变量分配内存
    dst_ir = new uint8_t[IMAGE_HEIGHT*IMAGE_WIDTH];
    timer = new QTimer(this);
    //8.设置滑动条，调节帧率
    ui->horizonFPS->setMinimum(15);
    ui->horizonFPS->setMaximum(200);
    ui->horizonFPS->setSingleStep(5);
    //9.提示连接相机
    ui->textInfo->append("<font color=\"#FF0000\">【INFO】No HRG Device detected!Please Connect to HRG-TOF CAMERA!</font>");
    //10.连接信号与槽函数
    paramdialog = new setparam(this);
    connect(timer,&QTimer::timeout,this,&Widget::ReadFrame);
    dis2 = connect(this,&Widget::HRGDepthIsReady,this,&Widget::PredictHand);
    connect(paramdialog,&setparam::SendIPandPort,this,&Widget::dealWithOkClicked);
        //多县城槽函数
    subThread = new QThread;
    connectingprocess = new ConnectThread;
    connect(this,&Widget::ToThread,connectingprocess,&ConnectThread::connectHRG);
        //连接成功或失败槽函数
    connect(connectingprocess,&ConnectThread::S_openedHRG,this,&Widget::S_updateAPP);
    connect(connectingprocess,&ConnectThread::F_openedHRG,this,&Widget::F_updateAPP);
    //11.设置“手势追踪”快捷键
    QShortcut *findgesture_CtrlF = new QShortcut(this);
        //设置键值，也就是设置快捷键.
    findgesture_CtrlF->setKey(tr("ctrl+f"));
        //这个成员函数挺关键的，设置是否会自动反复按键.也就是说，当你一直按住键盘ctrl+f时，会一直不停的调用对应的槽函数.
    findgesture_CtrlF->setAutoRepeat(false);
        //连接信号与槽，showSlot()是自定义的槽函数!
    connect(findgesture_CtrlF, &QShortcut::activated, this, &Widget::on_buttonTrain_clicked);
    connect(this,&Widget::CanDTW,this,&Widget::DynamicGesture);
}


/********************************************************
 * function:～Widget()
 * author:Zuo jiale
 * Date:2021-1-10
 * description:软件界面的析钩函数，实现对变量的回收，其中handfinder析钩的时候会将自己的手势库写入到本地MyGesture.txt中
 * Params:输入None
 *        输出None
 * ****************************************************/
Widget::~Widget()
{
   if(isConnected == true)
   {
       Hrg_StopStream(&handle);
       Hrg_CloseDevice(&handle);
   }
   delete handfinder; //handgesture
   delete[] dst_ir;
   delete ui;
}

/********************************************************
 * function:InitApp()
 * author:Zuo jiale
 * Date:2021-1-6
 * description:显示HRG的Logo
 * Params:输入None
 *        输出None
 * ****************************************************/
void Widget::InitApp()
{
    QImage *logo = new QImage;
    logo->load("../resource/HRG.png");
    ui->labelView->setPixmap(QPixmap::fromImage(*logo));
    ui->labelView->setScaledContents(true);
    ui->labelView->show();
    ui->labelDepth->setPixmap(QPixmap::fromImage(*logo));
    ui->labelDepth->setScaledContents(true);
    ui->labelDepth->show();
}


/********************************************************
 * function:dealWithOkClicked()
 * author:Zuo jiale
 * Date:2021-1-5
 * description:处理“connect连接子窗口”中ok按下的槽函数，用来连接HRG相机
 * Params:输入IPandPort：子窗口传来的IP和端口Port
 *        输出None
 * ****************************************************/
void Widget::dealWithOkClicked(std::vector<QString> IPandPort)
{
    // 连接相机ConnectHRGWithIPandPort，是耗时的计算函数
       QFuture<void> future = QtConcurrent::run(this,&Widget::ConnectHRGWithIPandPort,IPandPort);
       while(!future.isFinished())
       {
           QApplication::processEvents(QEventLoop::AllEvents, 100);
           break;
       }
}

/********************************************************
 * function:ConnectHRGWithIPandPort()
 * author:Zuo jiale
 * Date:2021-1-5
 * description:利用connectthread类传入thread进行多线程的方法，连接相机
 * Params:输入IPandPort：子窗口传来的IP和端口Port
 *        输出None
 *        信号signal：ToThread，给子线程函数发射信号，并传参ip和port
 * ****************************************************/
void Widget::ConnectHRGWithIPandPort(std::vector<QString> IPandPort)
{
    /*
     * function:在子窗口发送ip和port之后进行解析，并连接相机
     */
    ui->textInfo->append("<font color=\"#0000FF\">【INFO】Connecting the HRG......</font>");

    qRegisterMetaType<std::vector<QString>>("std::vector<QString>");
    qRegisterMetaType<Hrg_Dev_Info>("Hrg_Dev_Info*");
    qRegisterMetaType<Hrg_Dev_Handle>("Hrg_Dev_Handle*");
    connectingprocess->moveToThread(subThread);
    //子线程开始
    subThread->start();
    emit ToThread(IPandPort,&dev,&handle);
    return;
}


/********************************************************
 * function:on_buttonConnect_clicked()
 * author:Zuo jiale
 * Date:2021-1-5
 * description:软件界面connect按钮按下，调用子窗口显示
 * Params:输入None
 *        输出None
 * ****************************************************/
void Widget::on_buttonConnect_clicked()
{
    /*
     * function:"连接相机"按钮槽函数,显示连接子窗口setparam
     */
    paramdialog->setModal(true);
    paramdialog->show();
}

/********************************************************
 * function:convertTo3Channels()
 * author:Zuo jiale
 * Date:2021-1-5
 * description:将openCV中的灰度图C1 -》 RGB三通道的图C3
 * Params:输入binImg：8UC1的灰度图
 *        输出three_channel：8UC3的RGB三通道图
 * ****************************************************/
cv::Mat Widget::convertTo3Channels(const cv::Mat& binImg)
{
    cv::Mat three_channel = cv::Mat::zeros(binImg.rows,binImg.cols,CV_8UC3);
    std::vector<cv::Mat> channels;
    for (int i=0;i<3;i++)
    {
        channels.push_back(binImg);
    }
    merge(channels,three_channel);
    return three_channel;
}

/********************************************************
 * function:ReadFrame()
 * author:Zuo jiale
 * Date:2021-1-9
 * description:定时器timer的槽函数，用来在软件中显示、刷新图像
 * Params:输入None
 *        输出None
 *        发射信号：
 *         1.HRGDepthIsReady：给后续利用深度图进行手势追踪、识别模组发射信号
 *          2.HRGFrameIsReady：用于幅度图的显示
 * ****************************************************/
void Widget::ReadFrame()
{
    /*
     * function:定时器timer槽函数,读取准备好的一帧数据进行显示
     */
    if(0 == Hrg_GetFrame(&handle, &frame))
    {
        static int output_idx = 0;
        static std::array<AlgorithmOutput_F32, 10> output_data;//相机输出的数据流
        Hrg_GetDepthF32andAmplitudeData(&handle,&frame,
                                                    output_data[output_idx].depth.get(),
                                                    output_data[output_idx].amplitude.get());
        //一、深度图
        this->tof_depth = cv::Mat(IMAGE_HEIGHT, IMAGE_WIDTH, CV_32F, output_data[output_idx].depth.get()); //原始深度图
        //0.双边滤波，滤波后的图像放置在img_tof_depth_filter里面
        cv::Mat img_tof_depth_filter;
        cv::bilateralFilter(this->tof_depth*1000, img_tof_depth_filter, 20, 40, 10);
        cv::Mat tof_depth_f =img_tof_depth_filter/1000;
        //1.将处理后的tof_depth_f的数据拷贝到我们设定的Tof_depth上
        tof_depth_f.copyTo(tof_depth);

        cv::Mat Depth = tof_depth;
        double Min = 0.0; double Max =0.0;
        minMaxLoc(Depth, &Min, &Max);
        Depth.convertTo(depth_temp,CV_8U,255.0/(Max-Min),-255.0*Min/(Max-Min));
        cv::Mat depth_C3 = convertTo3Channels(depth_temp);
        cv::cvtColor(depth_C3, depth_C3, CV_BGR2RGB);
        HRGDepth = QImage((uchar*)(depth_C3.data), depth_C3.cols, depth_C3.rows, QImage::Format_RGB888);
        //2.显示深度图
        ui->labelDepth->setPixmap(QPixmap::fromImage(HRGDepth));
        ui->labelDepth->setScaledContents(true);
        ui->labelDepth->show();
        emit HRGDepthIsReady();//发射信号，depth数据准备好了

        //二、幅度图
        //1.opencv's ApplyColorMap function: 8UC1 -> 8UC3
        cv::Mat tof_amplitude= cv::Mat(IMAGE_HEIGHT, IMAGE_WIDTH, CV_16S, output_data[output_idx].amplitude.get()); //原始幅度图
        auto diff1 = 800 + std::numeric_limits<double>::epsilon();
        cv::Mat tof_amplitude_IR = tof_amplitude;
        tof_amplitude_IR.convertTo(tof_amplitude_IR, CV_8U, 255 / diff1);
        cv::applyColorMap(tof_amplitude_IR, tof_amplitude_IR, cv::COLORMAP_BONE);
        cvHRG_Frame=tof_amplitude_IR;
        //2.only RGB of Qt
        cv::cvtColor(cvHRG_Frame, cvHRG_Frame, CV_BGR2RGB);
        //3.更新成员HRGFrame
        HRGFrame = QImage((uchar*)(cvHRG_Frame.data), cvHRG_Frame.cols, cvHRG_Frame.rows, QImage::Format_RGB888);
        //4.更新完毕，触发信号
        emit HRGFrameIsReady();
        //5.显示幅度图
        ui->labelView->setPixmap(QPixmap::fromImage(HRGFrame));
        ui->labelView->setScaledContents(true);
        ui->labelView->show();

        //三、释放frame，更新index
        Hrg_FreeFrame(&handle, &frame);
        output_idx = output_idx < 9 ? output_idx + 1 : 0;
    }
}


/********************************************************
 * function:InitModel()
 * author:Zuo jiale
 * Date:2021-1-6
 * description:加载训练好的model，用来后续预测手势结果
 * Params:输入None
 *        输出None
 * ****************************************************/
void Widget::InitModel()
{
    /*
     * function:导入训练好的神经网络模型到程序中
     */
    try {
           module = torch::jit::load("../resource/HRG_C++.pt");
       }
       catch (const c10::Error& e) {
            ui->textInfo->append("<font color=\"#FF0000\">【INFO】Failed to load the Model!</font>");
           return;
       }
       ui->textInfo->append("<font color=\"#0000FF\">【INFO】Model loaded successful!</font>");
       return;
}

/********************************************************
 * function:PredictHand()
 * author:Zuo jiale
 * Date:2021-1-8
 * description:接受到信号HRGDepthIsReady，取出帧出来用model预测手势结果，并在lcd上显示手势结果
 * Params:输入None
 *        输出None
 *        发射信号：CanDTW
 * ****************************************************/
void Widget::PredictHand()
{
    //0.利用handfinder方法对深度数据进行手部的提取、分割
        //根据轮廓多少、轮廓面积进行筛选，避免误扣取、误判断
	cv::Mat temp_depth = tof_depth;
    cv::Rect rect;
    cv::Mat pick_hand = handfinder->PickupHandFromDepth(temp_depth,&rect);
    if(pick_hand.empty()) return;
    imshow("hand",pick_hand);

    //1.神经网络预测之前进行必要的图像预处理
    cv::Mat cvHRG_Frame1;
    cv::resize(pick_hand, cvHRG_Frame1, cv::Size(32, 32));  //3.2 将图片修剪成32×32的格式大小
    cv::Mat float_image;
    cvHRG_Frame1.convertTo(float_image, CV_32FC3, 1.0f / 255.0f);   //3.3 将图片像素0～255归一化到[0,1]区间
    float_image.convertTo(float_image, CV_32FC3, 1.0f, -0.5f);
    float_image.convertTo(float_image, CV_32FC3, 1.0f/0.5f);  //归一化到[-1,1]
    auto img_tensor = torch::from_blob(float_image.data, {1, 32, 32, 3});
    img_tensor = img_tensor.permute({0, 3, 1, 2});  //3.4 将图片格式[1,H，B，C]改成pytorch读取的[1,C，H，B]格式，并转为Tensor格式

    //2. 将预处理后的图片喂入网络
    torch::Tensor output = module.forward({img_tensor}).toTensor();
    //3.得到预测结果
    auto pred = output.argmax(1);
    //4.设置lcd风格和字体颜色
    ui->lcdPredict->setSegmentStyle(QLCDNumber::Flat); //有三种风格  如上
    ui->lcdPredict->setStyleSheet("color:#0000CD;"); //背景透明 设置字体色
    ui->lcdPredict->display(pred.item().toFloat());    //输出最大概率所在索引号，即预测结果

    //5.判断是否是“播放”cmd
    if( !this->isPlay)  //不是播放状态，才需要判断“播放”指令
    {
        static int cmdstart =0;
        if(pred.item().toFloat() == 3.0)
        {
            if(cmdstart == 5)//连续5帧
            {
                cmdstart  =0;
                //开始播放
                ui->textInfo->append("<font color=\"#9F5F9F\">【INFO】Start playing music!</font>");
                mp3->on_playButton_clicked();
                this->isPlay = true; //切换到“播放状态”
                return;
            }
            cmdstart++;
        }
        else cmdstart =0;
    }

    //6.播放状态前提下，才判断是否触发动态手势
    if(this->isPlay)
    {
        static int one_nums = 0;
        if(pred.item().toFloat() == 1.0)
        {
            if(lastisone)
            {
                one_nums ++;
            }
            if(one_nums == 1) //连续1+1=2帧
            {
                one_nums = 0;
                lastisone =false;
                //断开predict连接dis2
                disconnect(dis2);
                //可以动态追踪，发射信号CanDtw
                emit CanDTW();
                return;
            }
            lastisone =true;
        }
        else
        {
            lastisone =false;
            one_nums = 0;
        }
    }

    //7.播放状态下，才判断是“停止”
    if(this->isPlay)
    {
        static int cmdend =0;
        if(pred.item().toFloat() == 5.0)
        {
            if(cmdend == 5)
            {
                cmdend  =0;
                //停止
                ui->textInfo->append("<font color=\"#FF0000\">【INFO】Stop music!</font>");
                mp3->on_stopButton_clicked();
                this->isPlay = false;
                return;
            }
            cmdend++;
        }
        else cmdend =0;
    }

}

/********************************************************
 * function:on_horizonFPS_sliderMoved()
 * author:Zuo jiale
 * Date:2021-1-6
 * description:滑动条滑动之后触发的槽函数，用来设置timer的定时时间，时间越长刷新越慢，因此调节FPS
 * Params:输入position：滑动条滑动之后的位置
 *        输出None
 * ****************************************************/
void Widget::on_horizonFPS_sliderMoved(int position)
{
    /*
     * function:"FPS滑动条"槽函数,更新帧率
     */
    //帧率fps数字变换之后
    FPS = ui->horizonFPS->value();
    timer->stop();
    timer->start(FPS);
}

/********************************************************
 * function:on_buttonDisconnect_clicked()
 * author:Zuo jiale
 * Date:2021-1-6
 * description:软件中disconnect按钮按下，断开与相机的连接
 * Params:输入None
 *        输出None
 * ****************************************************/
void Widget::on_buttonDisconnect_clicked()
{
    /*
     * function:"disconnect"按钮槽函数,断开与相机的连接
     */
    QMessageBox::StandardButton defaultButton = QMessageBox::NoButton; //默认“否”
    QMessageBox::StandardButton result;
    result = QMessageBox::question(this,"Warning","Are you sure to DISCONNECT from HRG?",QMessageBox::Yes|QMessageBox::No |QMessageBox::Cancel,defaultButton);
    if(result == QMessageBox::Yes)
    {
        timer->stop(); //关闭定时器
        Hrg_StopStream(&handle);
        Hrg_CloseDevice(&handle);
        ui->buttonDisconnect->setEnabled(false);
        ui->buttonSave->setEnabled(false);
        ui->buttonConnect->setEnabled(true);
        ui->horizonFPS->setEnabled(false);
        ui->textInfo->append("<font color=\"#FF0000\">【INFO】Disconnect from HRG!</font> ");
        InitApp();
        ui->lcdPredict->setSegmentStyle(QLCDNumber::Outline);
        QMessageBox::about(this,"Warning","Disconnected form HRG!");
    }
    else if(result == QMessageBox::No || result == QMessageBox::Cancel)
    {
        return;
    }
    else return;
}


/********************************************************
 * function:on_buttonSave_clicked()
 * author:Zuo jiale
 * Date:2021-1-6
 * description:软件中save按钮按下，保存当前帧到本地目录
 * Params:输入None
 *        输出None
 * ****************************************************/
void Widget::on_buttonSave_clicked()
{
    /*
     * function:"Save Image"按钮槽函数,保存图形到本地
     */
    //保存图片
    timer->stop();  //把图像冻结，不然保存的不是刚刚那一帧
    QString fileName;
    fileName = QFileDialog::getSaveFileName(this,
        tr("Open Config"), "", tr("Image Files (*.png *.jpg *.bmp)"));

    if (!fileName.isNull())
    {
        fileName += ".jpg";
        cv::imwrite(fileName.toStdString() ,cvHRG_Frame);            //fileName是文件名
        QMessageBox::about(this,"Warning","Succesfully saved!");
        ui->textInfo->append("<font color=\"#00FF00\">【INFO】Saved the pic successful!</font> ");
    }
    timer->start(FPS);
}


/********************************************************
 * function:S_updateAPP()
 * author:Zuo jiale
 * Date:2021-1-6
 * description:子线程传回的信号判断“成功连接相机”，并对软件进行必要配置
 * Params:输入None
 *        输出None
 *        接受信号：子线程传回的S_openedHRG
 * ****************************************************/
void Widget::S_updateAPP()
{
    //成功连接相机
    //1.显示提示信息
    QMessageBox::about(this,"Warning","Sucessfully Connected!");
    ui->textInfo->append("<font color=\"#0000FF\">【INFO】Connected HRG successful!</font> ");
    //2.连接相机之后，获取数据流stream
    isConnected = true;
    //3.设置界面
    ui->buttonDisconnect->setEnabled(true);
    ui->buttonSave->setEnabled(true);
    ui->buttonConnect->setEnabled(false);
    ui->horizonFPS->setEnabled(true);
     //4.默认是“正常”模式
    ui->textInfo->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //5.开启定时器
    timer->start(FPS); //33ms,也就是30帧

    //6.mp3
    this->mp3->show();
}


/********************************************************
 * function:F_updateAPP()
 * author:Zuo jiale
 * Date:2021-1-6
 * description:子线程传回的信号判断“连接相机失败”，并对软件进行必要配置
 * Params:输入None
 *        输出None
 *        接受信号：子线程传回的F_openedHRG
 * ****************************************************/
void Widget::F_updateAPP()
{
    //失败：连接相机
    QMessageBox::about(this,"Warning","Faied to Connect!");
    ui->textInfo->append("<font color=\"#FF0000\">【INFO】Failed to connect HRG!</font>");
}

/********************************************************
 * function:DynamicGesture()
 * author:Zuo jiale
 * Date:2021-1-7
 * description:手势追踪开启，用来判断动态手势。连接HandTracking函数和HRGDepthIsReady信号的桥梁
 * Params:输入None
 *        输出None
 * ****************************************************/
void Widget::DynamicGesture()
{
    //gesture started function
    std::cout << "handtracking" << std::endl;
    ui->buttonTrain->setEnabled(false);
    dis = connect(this,&Widget::HRGDepthIsReady,this,&Widget::HandTracking);
}

/********************************************************
 * function:HandTracking()
 * author:Zuo jiale
 * Date:2021-1-7
 * description:判断动态手势的函数。并在手势结束之后，自己断开与HRGFrameIsReady信号的连接，等待下一次触发、重连
 * Params:输入None
 *        输出None
 *        接受信号：HRGDepthIsReady
 * ****************************************************/
void Widget::HandTracking()
{
    //1.图像处理
    //depth分割手
    cv::Mat temp_depth = tof_depth;
    cv::Mat pick_hand = handfinder->PickupHandFromDepth(temp_depth,this->MinRect);
    if(pick_hand.empty()) //轮廓太多，说明不是手势，而是噪点
    {
        if(!handfinder->gesture->FeatureMatrix.empty()) //不为空，说明中间动作被断了
        {
            //拿去判断
            ui->textInfo->append("gesture stoped!");
            std::cout << "end" << std::endl;
            //判断动态手势
            std::string HandResult = handfinder->JudgeFromGestureFeatureMatrix();
            QString DynamicHandResult = QString::fromStdString(HandResult);
            ui->textInfo->append(DynamicHandResult);
            disconnect(dis);
            dis2 = connect(this,&Widget::HRGDepthIsReady,this,&Widget::PredictHand);
            return;
        }
        return;
    }
    imshow("tracking",pick_hand);
    //此时轮廓正常，认为手势进入动态状态
    cv::rectangle(cvHRG_Frame, *MinRect,cv::Scalar(255,255,0),2,LINE_8);
    Point centralPoint = handfinder->GetCentralHandPoint(*MinRect);
    //draw route
    handfinder->DrawHandRoute(cvHRG_Frame,cvHRG_Frame,centralPoint);
    double theata = handfinder->CalculateAngelOfTwoPositions(4.25);
    if(theata != -1)
    {
        //该距离不是很短，需计算特征值
        int feature = handfinder->CalculateFeatureWithAngel(theata);
        std::cout << feature << std::endl;
        handfinder->gesture->FeatureMatrix.push_back(feature);
    }
    if(handfinder->isEndOfGesture(2.5,2.5))
    {
        //ui->textInfo->append("gesture stoped!");
        std::cout << "end" << std::endl;
        //判断动态手势
        std::string HandResult = handfinder->JudgeFromGestureFeatureMatrix();
        if(HandResult == "手势太短，无意义") return;
        QString DynamicHandResult = QString::fromStdString(HandResult);
        ui->textInfo->append(DynamicHandResult);
        //控制mp3
        if(HandResult == "增加音量")
        {
            mp3->volumeUp();
        }
        else if(HandResult == "减小音量")
        {
            mp3->volumeDown();
        }
        else if(HandResult == "下一首")
        {
            mp3->nextSong();
        }
        else if(HandResult == "上一首")
        {
            mp3->lastSong();
        }
        disconnect(dis);
        dis2 = connect(this,&Widget::HRGDepthIsReady,this,&Widget::PredictHand);
    }
}

/********************************************************
 * function:on_buttonTrain_clicked()
 * author:Zuo jiale
 * Date:2021-1-7
 * description:手势训练开启，用户可以增加新的自定义手势NewGesture或者扩展自己的手势库。连接TrainingGesture函数和HRGFrameIsReady信号的桥梁
 * Params:输入None
 *        输出None
 * ****************************************************/
void Widget::on_buttonTrain_clicked()
{
    //训练开启，增加新的自定义手势NewGesture
    dis = connect(this,&Widget::HRGFrameIsReady,this,&Widget::TrainingGesture);
}

/********************************************************
 * function:TrainingGesture()
 * author:Zuo jiale
 * Date:2021-1-7
 * description:训练手势的函数。并在手势结束之后，自己断开与HRGFrameIsReady信号的连接，等待下一次触发、重连
 * Params:输入None
 *        输出None
 *        接受信号：HRGFrameIsReady
 * ****************************************************/
void Widget::TrainingGesture()
{
    //1.图像处理
    cv::Mat temp = cvHRG_Frame;
    cv::Mat grayimg;
    cvtColor(temp,grayimg,COLOR_BGR2GRAY);
    cv::Mat binimg = handfinder->Binarization(grayimg,150,255);
    temp = convertTo3Channels(binimg);
    //2.手势追踪器handfinder对手势进行追踪、背景滤除、特征编码、dtw识别结果
    cv::Mat removeBGImg = handfinder->SplitHandFromBackground(temp,KNN);
    binimg = handfinder->Binarization(removeBGImg,120,255);
    cv::Mat dilateimg = handfinder->DilateImg(binimg,15);
    cv::Rect minrect =  handfinder->GetMinRect(dilateimg,1100);
    cv::rectangle(cvHRG_Frame, minrect,cv::Scalar(255,255,0),2,LINE_8);
    Point centralPoint = handfinder->GetCentralHandPoint(minrect);
    //draw route
    handfinder->DrawHandRoute(cvHRG_Frame,cvHRG_Frame,centralPoint);
    double theata = handfinder->CalculateAngelOfTwoPositions(4.25);
    if(theata != -1)
    {
        //该距离不是很短，需计算特征值
        int feature = handfinder->CalculateFeatureWithAngel(theata);
        std::cout << feature << std::endl;
        handfinder->gesture->FeatureMatrix.push_back(feature);
    }
    /*3.手势结束*/
    if(handfinder->isEndOfGesture(2.5,2.5))
    {
         ui->textInfo->append("gesture captured!");
         std::cout << "end" << std::endl;
         disconnect(dis);
         /*4.判断手势是否太短*/
        if(!handfinder->gesture->IsTooShort())
        {
            /**************添加动态手势*************/
            //5.判断是否是已经有的模板手势
            std::vector<double> handinfo;
            handinfo = handfinder->dtw->JudgeHandResultWithDTW(handfinder->gesture->FeatureMatrix);
            int minlabel = handinfo[0];
            double mindist = handinfo[1];
            //6.1.距离过大，未定义手势
            if(mindist > 1.0)
            {
                bool ok;
                QString newlabel = QInputDialog::getText(this, tr("No matching gesture!"),tr("Please input the NEW-LABEL of this gesture:"), QLineEdit::Normal ,0, &ok);
                //7.1 按下ok，愿意添加该新手势
                if (ok && !newlabel.isEmpty())
                {
                    std::vector<int>  newgesture;
                    newgesture = handfinder->gesture->FeatureMatrix;
                    newgesture.push_back(newlabel.toInt());
                    //添加到自己的库里面
                    handfinder->dtw->MyGeatureFeature.push_back(newgesture);
                    //将gesture里面的手势特征清除
                    handfinder->gesture->FeatureMatrix.clear();
                    return;
                }
                else  //7.2 按下cancel，不愿意添加该新手势
                {
                    //将gesture里面的手势特征清除
                    handfinder->gesture->FeatureMatrix.clear();
                    return;
                }

            }
            else  //6.2.手势库已有该手势
            {
                int res =  QMessageBox::warning(this,"Info",QString("Will you want to save this Gesture named:%1?").arg(minlabel),QMessageBox::Yes|QMessageBox::No);
                //7.3 按下Yes，愿意添加该旧手势
                if(res == QMessageBox::Yes)
                {
                    handfinder->gesture->FeatureMatrix.push_back(minlabel);
                    handfinder->dtw->MyGeatureFeature.push_back(handfinder->gesture->FeatureMatrix);
                    //将gesture里面的手势特征清除
                    handfinder->gesture->FeatureMatrix.clear();
                    return;
                }
                else //7.4 按下No，不愿意添加该旧手势
                {
                    bool ok;
                    QString newlabel = QInputDialog::getText(this, tr("Info"),tr("Please input the NEW-LABEL of this gesture:"), QLineEdit::Normal ,0, &ok);
                    if (ok && !newlabel.isEmpty())
                    {
                        std::vector<int>  newgesture;
                        newgesture = handfinder->gesture->FeatureMatrix;
                        newgesture.push_back(newlabel.toInt());
                        //添加到自己的库里面
                        handfinder->dtw->MyGeatureFeature.push_back(newgesture);
                        //将gesture里面的手势特征清除
                        handfinder->gesture->FeatureMatrix.clear();
                        return;
                    }
                    //将gesture里面的手势特征清除
                    handfinder->gesture->FeatureMatrix.clear();
                    return;
                }
            }
        }
        handfinder->gesture->FeatureMatrix.clear();
    }
}
