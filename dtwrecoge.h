/***dtwrecoge.h*********************************************************************/
#ifndef dtwrecoge_h
#define dtwrecoge_h

#include<stdio.h>
#include <iostream>
#include <vector>
#include<math.h>

#define DTWMAXNUM 2000
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>0?(a):(-(a)))
#define DTWVERYBIG 100000000.0

class DTW
{
public:
    DTW();
	~DTW();
    std::vector<double>  JudgeHandResultWithDTW(std::vector<int> work_gesture);
    int InsertOtherGesture(std::vector<int> train_gesture, int label);
    /*从文件读取加载*/
    void LoadGeatureFeatureFromTxt();
    /*写入文件*/
    void WriteGeatureFeatureToTxt();
    double DTWDistanceFun(std::vector<int> work_gesture, std::vector<int> template_gesture);
    /*自己建立的特征模板*/
    std::vector<std::vector<int>>  MyGeatureFeature;
};

#endif
