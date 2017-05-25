//头文件声明部分
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;


//全局变量声明部分
Mat g_srcImage, g_dstImage1, g_dstImage2, g_dstImage3;			//存储图片
int g_nBoxFilterValue = 3;			//方框滤波参数值
int g_nMeanBlurValue = 3;			//均值滤波参数值
int g_nGaussianBlurValue = 3;			//高斯滤波参数值

//全局函数声明部分
static void on_BoxFilter(int, void*);			//方框滤波
static void on_MeanBlur(int, void*);			//均值滤波
static void on_GaussianBlur(int, void*);			//高斯滤波


//main 函数
int main()
{
	
	//载入原图
	g_srcImage = imread("1.jpg", 1);
	if (!g_srcImage.data) { cout << "读取源图片错误！\n" << endl; return false; }

	//复制原图到三个Mat类型中
	g_dstImage1 = g_srcImage.clone();
	g_dstImage2 = g_srcImage.clone();
	g_dstImage3 = g_srcImage.clone();

	//显示原图
	namedWindow("【<0>原图窗口】", 1);
	imshow("【<0>原图窗口】", g_srcImage);

	//方框滤波
	//创建窗口
	namedWindow("【<1>方框滤波】", 1);
	//创建轨迹条 
	createTrackbar("内核值：", "【<1>方框滤波】", &g_nBoxFilterValue, 40, on_BoxFilter);
	on_BoxFilter(g_nBoxFilterValue, 0);

	//均值滤波
	//创建窗口
	namedWindow("【<2>均值滤波】", 1);
	//创建轨迹条 
	createTrackbar("内核值：", "【<2>均值滤波】", &g_nMeanBlurValue, 40, on_MeanBlur);
	on_MeanBlur(g_nMeanBlurValue, 0);

	//高斯滤波
	//创建窗口
	namedWindow("【<3>高斯滤波】", 1);
	//创建轨迹条 
	createTrackbar("内核值：", "【<3>高斯滤波】", &g_nGaussianBlurValue, 40, on_GaussianBlur);
	on_GaussianBlur(g_nGaussianBlurValue, 0);

	//按下q时退出
	while (char(waitKey(1)) != 'q') {};

	return 0;
}


//on_BoxFilter()函数
static void on_BoxFilter(int, void*)
{
	boxFilter(g_srcImage, g_dstImage1, -1, Size(g_nBoxFilterValue + 1, g_nBoxFilterValue + 1));
	imshow("【<1>方框滤波】", g_dstImage1);
}

//on_MeanBlur()函数
static void on_MeanBlur(int,void*)
{
	blur(g_srcImage, g_dstImage2, Size(g_nMeanBlurValue + 1, g_nMeanBlurValue + 1), Point(-1, -1));
	imshow("【<2>均值滤波】", g_dstImage2);

}

//on_GaussianBlur()函数
static void on_GaussianBlur(int, void*)
{
	GaussianBlur(g_srcImage, g_dstImage3, Size(g_nGaussianBlurValue * 2 + 1, g_nGaussianBlurValue * 2 + 1), 0, 0);
	imshow("【<3>高斯滤波】", g_dstImage3);
}