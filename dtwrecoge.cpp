/*dtwrecoge.cpp**************************************************************/

#include "dtwrecoge.h"
#include <iostream>
#include <vector>
#include <regex>
#include <fstream>

using namespace std;

/*****************************************************************
 * function:DTW()
 * author:Zuo jiale
 * Date:2020-12-30
 * description:DTW算法构造函数，从txt文件中初始化MyGesture矩阵
 * Param:输入None
 *              输出None
 * ***************************************************************/
DTW::DTW()
{
	LoadGeatureFeatureFromTxt();
}

DTW::~DTW()
{
	//写入到文件中
	WriteGeatureFeatureToTxt();
}


/*****************************************************************
 * function:LoadGeatureFeatureFromTxt()
 * author:Zuo jiale
 * Date:2020-12-30
 * description：从文件txt中读取到二维的vector中，每一行代别一个手势的特征+label
 * 		        其中每行最后一位数字代表label，其余代表特征序列
 * Param:输入None
 *              输出None
 * ***************************************************************/
void DTW::LoadGeatureFeatureFromTxt()
{
	vector<int> temp_line; //先按行村到一个vector里面
	string line;
	ifstream MyGesturetxt("../resource/MyGesture.txt");  //读入文件
	regex pat_regex("[[:digit:]]+");  //匹配原则，这里代表一个或多个数字
	while(getline(MyGesturetxt, line)) 
	{  //按行读取
		for (sregex_iterator it(line.begin(), line.end(), pat_regex), end_it; it != end_it; ++it)
		{  //表达式匹配，匹配一行中所有满足条件的字符
			temp_line.push_back(stoi(it->str()));  //将数据转化为int型并存入一维vector中
		}
		MyGeatureFeature.push_back(temp_line);  //保存所有数据
		temp_line.clear();
	}
}

/*****************************************************************
 * function:DTWDistanceFun()
 * author:Zuo jiale
 * Date:2020-12-30
 * description：计算两个数组的最短距离，DTW算法核心：动态规划
 * Param:输入work_gesture：平时生成的手势特征序列
 *              输入template_gesture：自己平时存的手势特征模板
 * 	    输出mindist：两条数组的最短距离
 * ***************************************************************/
double DTW::DTWDistanceFun(std::vector<int> work_gesture, std::vector<int> template_gesture)
{
	std::vector<std::vector<double>> distance(DTWMAXNUM,std::vector<double>(DTWMAXNUM,DTWVERYBIG)); /*保存距离*/
	double mindist;
	int work_gesture_size = work_gesture.size();
	int template_gesture_size = template_gesture.size();
	/*检查参数的有效性*/
	if(work_gesture_size > DTWMAXNUM || template_gesture_size > DTWMAXNUM)
	{
		//printf("Too big number\n");
		return -1.0;
	}
	
	/*动态规划求最小距离*/
	distance[0][0] = (double)2*ABS(work_gesture[0]-template_gesture[0]);
	for(int i=1;i<work_gesture_size;i++)
	{
		distance[i][0]=distance[i-1][0] + ABS(work_gesture[i]-template_gesture[0]);
	}
	for(int j=1;j<template_gesture_size;j++)
	{
		distance[0][j]=distance[0][j-1] + ABS(work_gesture[0]-template_gesture[j]);
	}
	for(int j=1;j<template_gesture_size;j++)
	{
		for(int i=1;i<work_gesture_size;i++)
		{
			//有三种可能路径到distance[i][j]:左边、下边、左下方
			//分别计算三种可能路径的最小距离，并取最小值，计为从distance[0][0]到distance[i][j]的最小距离
			double minpath1 = distance[i-1][j] + ABS(work_gesture[i]-template_gesture[j]);
			double minpath2 = distance[i-1][j-1] + 2*ABS(work_gesture[i]-template_gesture[j]);
			double minpath3 = distance[i][j-1] + ABS(work_gesture[i]-template_gesture[j]);
			minpath2 = MIN(minpath1,minpath2);
			minpath3 = MIN(minpath2,minpath3);
			distance[i][j] = minpath3;
		}
	}
	//计算所有的最小距离举证distance之后，返回两个数组指尖的最小距离
	mindist=distance[work_gesture_size-1][template_gesture_size-1]/((double)(work_gesture_size+template_gesture_size)); //最后算出两个数组距离
	return mindist;
}

/*****************************************************************
 * function:JudgeHandResultWithDTW()
 * author:Zuo jiale
 * Date:2020-12-30
 * description：计算两个数组的最短距离，DTW算法核心：动态规划
 * Param:输入work_gesture：平时生成的手势特征序列
 *              输出HandInfo：识别的手势信息，第一位表示的是识别的最小距离的label，第二位表示的是最小距离
 * ***************************************************************/
std::vector<double>  DTW::JudgeHandResultWithDTW(std::vector<int> work_gesture)
{
	std::vector<double> HandInfo(2,1000000); //label-dist
	for(std::vector<int> each_gesture : MyGeatureFeature)
	{
		int label = each_gesture.back();
		each_gesture.pop_back();   //把label删掉
		double dist = DTWDistanceFun(work_gesture, each_gesture);
		//取最小值mindist的label作为手势的答案
		if(HandInfo[1]  >= dist)
		{
			HandInfo[1]  = dist;
			HandInfo[0]  = label;
		}
	}
	return HandInfo;
} 


/*****************************************************************
 * function:InsertOtherGesture()
 * author:Zuo jiale
 * Date:2020-12-30
 * description：增加自定义的训练手势，或者扩展自身的手势库
 * Param:输入train_gesture：训练得到的手势特征序列
 *              输出None
 * ***************************************************************/
int DTW::InsertOtherGesture(std::vector<int> train_gesture, int label)
{
	//判断是否是已经有的模板手势
	std::vector<double> handinfo;
	handinfo = JudgeHandResultWithDTW(train_gesture);
	int minlabel = handinfo[0];
	double mindist = handinfo[1];
	std::cout << mindist << std::endl;
	if(mindist > 1.5)
	{
		int newlabel;
		std::cout << "未定义该手势,请输入该手势label：" ;
		std::cin >> newlabel ;
		std::vector<int>  newgesture;
		newgesture = train_gesture;
		newgesture.push_back(newlabel);
		//添加到自己的库里面
		this->MyGeatureFeature.push_back(newgesture);
		return 0;
	}
	else
	{
		//已有
		train_gesture.push_back(minlabel);
		this->MyGeatureFeature.push_back(train_gesture);	
		return 0;
	}
}

/*****************************************************************
 * function:WriteGeatureFeatureToTxt()
 * author:Zuo jiale
 * Date:2021-1-01
 * description：将手势特征序列写入到txt
 * Param:输入insertgesture：要写的特征序列
 *              输出None
 * ***************************************************************/
void DTW::WriteGeatureFeatureToTxt()
{
	ofstream out( "../resource/MyGesture.txt");
	for(auto x : this->MyGeatureFeature)
	{
		for(auto y : x)
		{
			out << y  <<' ';
		}
		out << std::endl;
	}
	out.close();
}
