#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;


int main()
{
	Mat srcImage = imread("G:/timg.jpg");
	imshow("show1", srcImage);
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat dstImage;
	erode(srcImage, dstImage, element);
	imshow("show2", dstImage);
	waitKey(0);

	return 0;


}