#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
using namespace cv;

int main()
{
	Mat srcImage = imread("G:/timg.jpg");
	imshow("src image", srcImage);
	Mat edge, grayImage;
	cvtColor(srcImage, grayImage, CV_BGR2GRAY);
	blur(grayImage, edge, Size(3, 3));
	Canny(edge, edge, 3, 9, 3);
	imshow("canny show", edge);
	waitKey(0);
	return 0;
}