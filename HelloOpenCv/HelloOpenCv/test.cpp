#include<opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat img = imread("G:/timg.jpg");
	imshow("showing photo", img);
	waitKey(6000);
}