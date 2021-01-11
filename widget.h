#pragma once
#pragma execution_character_set("utf-8")//display chinese words
#ifndef WIDGET_H
#define WIDGET_H

/*
 * 1.包含torch头文件
*/
#include <torch/script.h>
#include <torch/torch.h>  //注意：这个torch.h需要放在最顶端，这是最坑的

#include <QObject>
#include <QWidget>

#include <QThread>
#include <QProgressDialog>

/*
 * 2.包含Timer头文件
*/
#include <QTimer>  //定时器
/*
 * 3.包含OpenCV头文件
*/
#include <opencv/cv.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

#include <QMetaType>

/*
 * 4.包含自己头文件
*/
extern "C++"
{
    #include "HrgTofApi.h"
    #include "setparam.h"
    #include "connectthread.h"  //多线程
    #include "handfinder.h"
    #include "mp3.h"
}

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
signals:
    /*
     * function:A signal when the HRGFrame for opencv is ready
     */
    void ToThread(std::vector<QString> IPandPort, Hrg_Dev_Info *dev, Hrg_Dev_Handle *handle);
    void HRGFrameIsReady(); //帧准备完毕，可以预测
    void HRGDepthIsReady(); //深度数据准备完毕
    void CanDTW(); //可以动态手势追踪

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void InitApp();
    /*
     * function:Init a trained ResNet18 model to c++ program
     */
    void InitModel();
    /*
     * function:Convert the binary Image(Channel 1)to RGB image(Channel 3)
     */
    cv::Mat convertTo3Channels(const cv::Mat& binImg);
    /*
     * function:To read Frame and to show in the QT label
     */
    void ReadFrame(); //Read the Frame
    /*
     * function:To predict hand result with the HRG frame for openCV
     */
    void PredictHand();
    void ConnectHRGWithIPandPort(std::vector<QString> IPandPort);


private slots:
    void on_buttonConnect_clicked();
    void on_horizonFPS_sliderMoved(int position);

    void on_buttonDisconnect_clicked();

    void on_buttonSave_clicked();
    void dealWithOkClicked(std::vector<QString> IPandPort);

    void S_updateAPP();
    void F_updateAPP();
    void DynamicGesture();
    void HandTracking(); //hand track
    void TrainingGesture();//training gesture

    void on_buttonTrain_clicked();

private:
    Ui::Widget *ui;
    HandFinder *handfinder; //handgesture
    QMetaObject::Connection dis; //
    QMetaObject::Connection dis2; //
    bool isConnected = false; //相机是否连接过
    setparam *paramdialog; //设置连接参数的子窗口
    torch::jit::script::Module module; //深度学习网络模型
    int FPS=10; //相机初始帧率为20帧，单位为ms
    QTimer* timer;  //用来定时获取数据的定时器Timer
    Hrg_Dev_Info dev; //相机实例化对象device
    Hrg_Dev_Handle handle; //相机连接方式的句柄
    Hrg_Frame frame; //HRG原始数据的一帧
    cv::Mat cvHRG_Frame;  //HRG转换到opencv的一帧
    QImage HRGFrame;  //HRG转换到QImage的一帧
    //深度图
    uint8_t* dst_ir;//深度相机分辨率是240×288，所以存到一个这样的数组里面
    cv::Mat tof_depth; //原始深度图
    cv::Mat depth_temp;
    QImage HRGDepth;  //depth深度图
    cv::Rect *MinRect = new cv::Rect;
    bool lastisone = false;
    //mp3
    Mp3 *mp3 = new Mp3;
    bool isPlay = false; //判断是否在播放
    //多线程
    QThread *subThread;
    ConnectThread *connectingprocess;

};

Q_DECLARE_METATYPE(std::vector<QString>);

#endif // WIDGET_H
