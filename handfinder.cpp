#include "handfinder.h"
#include "opencv2/imgproc/imgproc.hpp"  
#include "opencv2/highgui/highgui.hpp"  
#include "opencv2/video.hpp"
#include <iostream>
#include<string>


using namespace cv;
using namespace std;

/*********************************
 * function:IsTooShort()
 * author:Zuo jiale
 * Date:2020-12-28
 * description:判断手势的特征矩阵是否过短
 *              true：过短，说明手势没有意义
 *              false：正常
 * *******************************/
bool Gesture::IsTooShort()
{
    if(this->FeatureMatrix.size() <= 3)
    {
        return true;
    }
    else return false;
}


/*********************************
 * function:HandFinder()
 * author:Zuo jiale
 * Date:2020-12-28
 * description:构造函数 和 析钩函数
 * *******************************/
HandFinder::HandFinder()
{
    this->gesture = new Gesture;
	this->dtw = new DTW;
}


HandFinder::~HandFinder()
{
    if(gesture != NULL)
    {
        delete gesture;
    }
	if(dtw != NULL)
    {
        delete dtw;
    }
}


/********************************************************
 * function:convertTo3Channels()
 * author:Zuo jiale
 * Date:2021-1-5
 * description:将openCV中的灰度图C1 -》 RGB三通道的图C3
 * Params:输入binImg：8UC1的灰度图
 *        输出three_channel：8UC3的RGB三通道图
 * ****************************************************/
cv::Mat HandFinder::ConvertTo3Channels(const cv::Mat& binImg)
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


Mat  HandFinder::PickupHandFromDepth(Mat Tof_Depth,Rect* MinRect)
{
	Mat src = Tof_Depth;
    Tof_Depth.setTo(100, src < 0.1);
    //imshow("1",Tof_Depth);
    cv::Mat tof_depth1;
    cv::blur(src, tof_depth1, cv::Size(3, 3), cv::Point(-1, -1), cv::BORDER_DEFAULT);
    //imshow("2",tof_depth1);
    double mindist = 0.0;
    minMaxLoc(tof_depth1, &mindist);
    double distThread = mindist + 0.2;
    src.setTo(0.0, src > distThread);
    //imshow("3",src);
    
    double Min = 0.0; double Max =0.0;
    minMaxLoc(src, &Min, &Max);
    src.convertTo(src,CV_8U,255.0/(Max-Min),-255.0*Min/(Max-Min));
	//二值化
	cv::Mat binary = Binarization(src, 100, 255);
	//imshow("4",binary);
	
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
    findContours(binary, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_NONE, Point());
    cv::Mat nullmat;
    if(contours.size() >= 30) return nullmat;
	
	double bestArea=0;
    vector<Point> bestContour;
    for (int i = 0; i < contours.size(); i++)
    {
        //contours[i]代表的是第i个轮廓
        double area = cv::contourArea(contours[i],false);
        if(area < 500)
        {
            continue; //小于阈值面积的轮廓直接舍去
        }
        else if(area >= bestArea) //大于阈值面积的需要再和最大面积比较，找到最大
        {
            bestArea = area;
            bestContour = contours[i];
        }
    }
    //判断面积：
    //std::cout << "area;" << bestArea << std::endl;
    if(bestArea >= 5000) return nullmat;
    // 最大外接轮廓
    *MinRect = cv::boundingRect(bestContour);
	//计算正方形框
	cv::Point centralPoint = GetCentralHandPoint(*MinRect);
	int width = MinRect->width;
	int height = MinRect->height;
	int largesize = width>height?width:height;
	cv::Rect squreRect(centralPoint.x-0.5*largesize, centralPoint.y-0.5*largesize, largesize, largesize);
	cv::Rect wholeRect(0,0,Tof_Depth.cols,Tof_Depth.rows);
	squreRect = squreRect & wholeRect;
	
	//剪切
	cv::Mat aa = this->ConvertTo3Channels(binary);
	cv::Mat temp1 = aa(squreRect);
    return temp1;
}


/*********************************
 * function:SplitHandFromBackground()
 * author:Zuo jiale
 * Date:2020-12-27
 * description:输入frame:RGB的帧
 *              输入bsType：提供2种过滤器KNN和MOG2,默认选择KNN
 *              输出bsmaskKNN：过滤器过滤背景之后的单通道图像（灰度）
 * *******************************/
Mat HandFinder::SplitHandFromBackground(Mat frame,int bsType=KNN)
{
    //初始化BS
    Mat bsmaskMOG2,bsmaskKNN;
    if(bsType == MOG2) 
    {
        // MOG BS
        Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3),Point(-1,-1));
        pMOG2->apply(frame, bsmaskMOG2);
        //形态学操作--开操作，去除小的噪声morphologyEx()
        morphologyEx(bsmaskMOG2, bsmaskMOG2, MORPH_OPEN, kernel, Point(-1, -1));
        return bsmaskMOG2;
    }
    else if(bsType == KNN)
    {
        pKNN->apply(frame, bsmaskKNN);
        return bsmaskKNN;
    }
    else cout << "no matching type for bs!" << endl;
}

/*********************************
 * function:Binarization()
 * author:Zuo jiale
 * Date:2020-12-26
 * description:输入src:单通道的灰度图
 *              输入threshold：二值化阈值
 *              输入maxvalue：像素最大值
 *              输出result：得到二值化图像
 * *******************************/
Mat HandFinder::Binarization(Mat src,int threshold=60,int maxvalue=255)
{
    // 转为二值图  
    Mat result;
	cv::threshold(src, result, threshold, maxvalue, CV_THRESH_BINARY);
    //CV_THRESH_BINARY：
        //if value < threshold: value =0;
        //if value >= threshold :value = maxvalue
    return result;
}


/*********************************
 * function:DilateImg()
 * author:Zuo jiale
 * Date:2020-12-26
 * description:输入src:二值化的图
 *              输入coresize：核的大小
 *              输出dst：膨胀之后的结果图
 * *******************************/
Mat HandFinder::DilateImg(Mat src,int coresize=15)
{
    Mat dst;
    Mat element = getStructuringElement(MORPH_RECT,Size(coresize,coresize));
	dilate(src, dst, element);
    return dst;
}

/*********************************
 * function:ErodeImg()
 * author:Zuo jiale
 * Date:2020-12-26
 * description:输入src:二值化的图
 *              输入coresize：核的大小
 *              输出dst：腐蚀之后的结果图
 * *******************************/
Mat HandFinder::ErodeImg(Mat src,int coresize=15)
{
    Mat dst;
    Mat element = getStructuringElement(MORPH_RECT,Size(coresize,coresize));
	erode(src, dst, element);
    return dst;
}



/*********************************
 * function:GetMinRect()
 * author:Zuo jiale
 * Date:2020-12-26
 * description:输入binImg:处理后的二值化图像
 *              输入areaThreshold：面积阈值
 *              输出MinRect：得到的轮廓的最大外接矩形Rect
 * *******************************/
cv::Rect HandFinder::GetMinRect(cv::Mat binImg,double areaThreshold=1000) //二值化之后的image
{
    cv::Rect MinRect;
	vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    
    findContours(binImg, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_NONE, Point());
    double bestArea=0;
    vector<Point> bestContour;
    for (int i = 0; i < contours.size(); i++)
    {
        //contours[i]代表的是第i个轮廓
        double area = cv::contourArea(contours[i],false);
        if(area < areaThreshold)
        {
            continue; //小于阈值面积的轮廓直接舍去
        }
        else if(area >= bestArea) //大于阈值面积的需要再和最大面积比较，找到最大
        {
            bestArea = area;
            bestContour = contours[i];
        }
    }
    // 最大外接轮廓
    MinRect = cv::boundingRect(bestContour);
    return MinRect;
}



/*********************************
 * function:GetCentralHandPoint()
 * author:Zuo jiale
 * Date:2020-12-26
 * description:输入rect:最大外接矩形        
 *              输出Point：计算得到的中心点xy
 * *******************************/
Point HandFinder::GetCentralHandPoint(cv::Rect rect)//得到手的中心点
{
    Point centralPoint;
    centralPoint.x = (rect.tl().x + rect.br().x) / 2;
    centralPoint.y = (rect.tl().y + rect.br().y) / 2;
    return centralPoint;
}



/*********************************
 * function:DrawHandRoute()
 * author:Zuo jiale
 * Date:2020-12-27
 * description:输入src:原图
 *              输出dst：绘制的轨迹的图  
 *              输入currentHandPosition：当前手的坐标
 * *******************************/
void HandFinder::DrawHandRoute(Mat src, Mat &dst,Point currentHandPosition) //绘制两帧之间质心的连线，默认设置为每5帧识别
{
    if(this->lastandcurrentPositions.size()==0)
    {
        dst =src;
        this->lastandcurrentPositions.push_back(currentHandPosition);
        return;
    }
    else if(this->lastandcurrentPositions.size()==1)
    {
        dst = src;
        this->lastandcurrentPositions.push_back(currentHandPosition);
        cv::line(dst, lastandcurrentPositions[0], lastandcurrentPositions[1], Scalar(0, 90, 90), 3);
        return;
    }
    else if(this->lastandcurrentPositions.size()==2)
    {
        dst = src;
        Point temp= lastandcurrentPositions[1];
        lastandcurrentPositions[0] = temp;
        this->lastandcurrentPositions.pop_back();
        this->lastandcurrentPositions.push_back(currentHandPosition);
        cv::line(dst, lastandcurrentPositions[0], lastandcurrentPositions[1], Scalar(0, 90, 90), 3);
        return;
    }
}


/*********************************
 * function:isEndOfGesture()
 * author:Zuo jiale
 * Date:2020-12-27
 * description:输入x_thres:x方向上的阈值
 *             输入y_thres:y方向上的阈值
 *             输出bool：停止true，未停止false
 * *******************************/
bool HandFinder::isEndOfGesture(int x_thres, int y_thres)//判断是否结束动作
{
    if(this->lastandcurrentPositions.size() == 2)
    {
    	static int index =0;
        static bool lastisend = false;
        if(Abs(lastandcurrentPositions[1].x - lastandcurrentPositions[0].x) <= x_thres && Abs(lastandcurrentPositions[1].y - lastandcurrentPositions[0].y) <= y_thres)  //符合停止条件
        {
        	if(lastisend)
        	{
        		index++;
		        if(index ==1)  //1+1,连续2帧符合停止条件
		        {
		            index = 0;
		            lastisend = false; //视为停止，恢复变量
		            this->lastandcurrentPositions.clear(); //动作结束，清空轨迹数组
		            return true;
		        }
        	}
        	lastisend = true;
            return false;
        }
        else //符合停止条件，返回false
        {
        	lastisend = false;
        	index = 0; //恢复变量
        	return false;
        }
    }
    return false;
}


/*********************************
 * function:CalculateAngelOfTwoPositions()
 * author:Zuo jiale
 * Date:2020-12-28
 * description:输入double distThres：对距离进行筛选，dist较小的当作无效特征，无需计算，默认dist=4.25（对应xy是正负3的变动，对应手势停止动作）
 *             输出theata:范围：[0,360],表示向量vc到x轴正向的夹角
 *                        -1:无效特征
 * *******************************/
double  HandFinder::CalculateAngelOfTwoPositions(double distThres=4.25) 
{
    /*
        theata:表示向量vc到x轴正向的夹角，范围：[0,360]
    */
    //计算向量坐标
    if(this->lastandcurrentPositions.size() == 2)
    {
    	Point vc;
		vc.x = this->lastandcurrentPositions[1].x - this->lastandcurrentPositions[0].x;
		vc.y = this->lastandcurrentPositions[1].y - this->lastandcurrentPositions[0].y;
	   //计算距离dist
		double dist = (double)sqrt(vc.x*vc.x + vc.y*vc.y);
		//对距离进行筛选，dist较小的当作无效特征，无需计算
		if(dist <= distThres) return -1;
		//根据向量坐标xy，计算与x轴正向夹角theata
		double theata = dist > 0?(double)((double)asin(vc.y/dist) / Pi * 180) : 0;
		if(vc.x < 0)
		{
		    theata = 180.0000 - theata;
		}
		if(vc.x >= 0 && vc.y <0)
		{
			theata = 360.0000 + theata;
		}
		return theata;
	}
	return -1;
    
}


/*********************************
 * function:CalculateFeatureWithAngel()
 * author:Zuo jiale
 * Date:2020-12-28
 * description:输入theata:计算得到的夹角
 *             输出feture:范围[1,12]，将0-360度按照每30度为1档，共12档，对角度进行编码
 * *******************************/
int HandFinder::CalculateFeatureWithAngel(double theata)
{
    if(0 <= theata && theata <30 )
    {
        return 1;
    }
    if(30 <= theata && theata <60 )
    {
        return 2;
    }
    if(60 <= theata && theata <90 )
    {
        return 3;
    }
    if(90 <= theata && theata <120 )
    {
        return 4;
    }
    if(120 <= theata && theata <150 )
    {
        return 5;
    }
    if(150 <= theata && theata <180 )
    {
        return 6;
    }
    if(180 <= theata && theata <210 )
    {
        return 7;
    }
    if(210 <= theata && theata <240 )
    {
        return 8;
    }
    if(240 <= theata && theata <270 )
    {
        return 9;
    }
    if(270 <= theata && theata <300 )
    {
        return 10;
    }
    if(300 <= theata && theata <330 )
    {
        return 11;
    }
    if(330 <= theata && theata <360 )
    {
        return 12;
    }
    
}




/*********************************
 * function:JudgeFromGestureFeatureMatrix()
 * author:Zuo jiale
 * Date:2020-12-28
 * description:输入None
 *             输出DynamicHandResult:对动态手势的识别结果
 * *******************************/
std::string HandFinder::JudgeFromGestureFeatureMatrix()
{
	std::string  handresult;
    if(this->gesture->IsTooShort() == true)
    {
        //too short
        //std::cout << "手势太短，无意义" << std::endl;
        handresult = "手势太短，无意义";
        this->gesture->FeatureMatrix.clear();//清空手势特征矩阵
        return handresult;
    }

    //DTW
    int DynamicHandResult;
    double mindist;
    std::vector<double> handinfo;
    handinfo = this->dtw->JudgeHandResultWithDTW(this->gesture->FeatureMatrix);
    DynamicHandResult = handinfo[0];
    mindist = handinfo[1];
    
    //show result
    if(DynamicHandResult == 8426 && mindist < 1)  {handresult = "减小音量";}
    else if(DynamicHandResult == 2486 && mindist < 1)  {handresult = "增加音量";}
    else if(DynamicHandResult == 654 && mindist < 1)  {handresult = "上一首";}
    else if(DynamicHandResult == 456 && mindist < 1)  {handresult = "下一首";}
    else {handresult = "未定义该手势";}
    std::cout << "Result is:" << DynamicHandResult << std::endl;
    
    //识别结束之后，将上一次的特征矩阵清空，清空手势特征举证
    this->gesture->FeatureMatrix.clear();//清空手势特征矩阵
    return handresult;
}
