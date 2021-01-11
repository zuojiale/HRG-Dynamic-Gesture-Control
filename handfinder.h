#ifndef _HANDFINDER_H_ 
#define _HANDFINDER_H_ 
//结构体和函数声明....
#include "opencv2/imgproc/imgproc.hpp"  
#include "opencv2/highgui/highgui.hpp"  
#include "opencv2/video.hpp"
#include <iostream>
#include <vector>

#include "dtwrecoge.h"  //DTW

using namespace cv;


#define MOG2 0
#define KNN 1
#define Abs(x) ((x)>=0 ? (x):(-(x))) 
#define Pi 3.14159

class Gesture
{
public:
    std::vector<int> FeatureMatrix; //手势对应的特征矩阵
    bool IsTooShort();
};


class HandFinder
{
public:
    HandFinder();
    ~HandFinder();
    Gesture *gesture; //手势
    DTW *dtw;

	cv::Mat ConvertTo3Channels(const cv::Mat& binImg);
    Mat  PickupHandFromDepth(Mat Tof_Depth,Rect* MinRect);
    
    Mat SplitHandFromBackground(Mat frame,int bsType);//背景去除
    Mat Binarization(Mat src,int threshold,int maxvalue);//二值化
    Mat DilateImg(Mat src,int coresize);//膨胀函数
    Mat ErodeImg(Mat src,int coresize);//腐蚀函数
    cv::Rect GetMinRect(cv::Mat binImg,double areaThreshold); //得到最大面积的轮廓的最大矩形框
    Point GetCentralHandPoint(cv::Rect rect);//得到手的中心点
    void DrawHandRoute(Mat src, Mat &dst, Point currentHandPosition);//绘制两帧之间质心的连线，默认设置为每5帧识别
    bool isEndOfGesture(int x_thres, int y_thres); //判断是否结束动作
    double CalculateAngelOfTwoPositions(double distThres);//计算角度,distThres默认=4.25
    int CalculateFeatureWithAngel(double theata);//计算特征值 1-12
    std::string JudgeFromGestureFeatureMatrix();//返回手势识别结果

private:
    Ptr<cv::BackgroundSubtractor> pMOG2 = cv::createBackgroundSubtractorMOG2();
    Ptr<cv::BackgroundSubtractor> pKNN = cv::createBackgroundSubtractorKNN();
    std::vector<Point> lastandcurrentPositions;//维护一个2个POint的vector，前：上一帧坐标，后：现在的坐标，用来绘制
};
#endif
