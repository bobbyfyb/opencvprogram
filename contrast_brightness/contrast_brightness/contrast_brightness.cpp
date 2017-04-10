#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<iostream>
using namespace std;
using namespace cv;


static void on_ContrastAndBright(int, void *);			//call back function

int g_nContrastValue;			//contrast value
int g_nBrightValue;				//brightness value
Mat g_srcImage, g_dstImage;

int main()
{
	//read in image
	g_srcImage = imread("F:/opencv program/contrast_brightness/1.jpg");
	if (!g_srcImage.data) { cout << "reading error!" << endl; }
	g_dstImage = Mat::zeros(g_srcImage.size(), g_srcImage.type());

	g_nContrastValue = 80;			//initiate contrast value
	g_nBrightValue = 80;			//initiate brightness value

	//create dest_image window
	namedWindow("dest_image", 1);			

	//create trackbar
	createTrackbar("contrast", "dest_image", &g_nContrastValue, 300, on_ContrastAndBright);
	createTrackbar("brightness", "dest_image", &g_nBrightValue, 300, on_ContrastAndBright);

	//inititate call back function
	on_ContrastAndBright(g_nContrastValue, 0);
	on_ContrastAndBright(g_nBrightValue, 0);

	while(char(waitKey(1))!='q'){}
	return 0;

}

static void on_ContrastAndBright(int,void *)
{
	//create window
	namedWindow("src_image", 1);

	for (int j = 0; j < g_srcImage.rows; j++)
		for (int i = 0; i < g_srcImage.cols; i++)
			for (int c = 0; c < 3; c++)
				g_dstImage.at<Vec3b>(j, i)[c] = saturate_cast<uchar>((g_nContrastValue*0.01)*(g_srcImage.at<Vec3b>(j, i)[c]) + g_nBrightValue);

	//show image
	imshow("src_image", g_srcImage);
	imshow("dest_image", g_dstImage);
}