//ͷ�ļ���������
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;


//ȫ�ֱ�����������
Mat g_srcImage, g_dstImage1, g_dstImage2, g_dstImage3;			//�洢ͼƬ
int g_nBoxFilterValue = 3;			//�����˲�����ֵ
int g_nMeanBlurValue = 3;			//��ֵ�˲�����ֵ
int g_nGaussianBlurValue = 3;			//��˹�˲�����ֵ

//ȫ�ֺ�����������
static void on_BoxFilter(int, void*);			//�����˲�
static void on_MeanBlur(int, void*);			//��ֵ�˲�
static void on_GaussianBlur(int, void*);			//��˹�˲�


//main ����
int main()
{
	
	//����ԭͼ
	g_srcImage = imread("1.jpg", 1);
	if (!g_srcImage.data) { cout << "��ȡԴͼƬ����\n" << endl; return false; }

	//����ԭͼ������Mat������
	g_dstImage1 = g_srcImage.clone();
	g_dstImage2 = g_srcImage.clone();
	g_dstImage3 = g_srcImage.clone();

	//��ʾԭͼ
	namedWindow("��<0>ԭͼ���ڡ�", 1);
	imshow("��<0>ԭͼ���ڡ�", g_srcImage);

	//�����˲�
	//��������
	namedWindow("��<1>�����˲���", 1);
	//�����켣�� 
	createTrackbar("�ں�ֵ��", "��<1>�����˲���", &g_nBoxFilterValue, 40, on_BoxFilter);
	on_BoxFilter(g_nBoxFilterValue, 0);

	//��ֵ�˲�
	//��������
	namedWindow("��<2>��ֵ�˲���", 1);
	//�����켣�� 
	createTrackbar("�ں�ֵ��", "��<2>��ֵ�˲���", &g_nMeanBlurValue, 40, on_MeanBlur);
	on_MeanBlur(g_nMeanBlurValue, 0);

	//��˹�˲�
	//��������
	namedWindow("��<3>��˹�˲���", 1);
	//�����켣�� 
	createTrackbar("�ں�ֵ��", "��<3>��˹�˲���", &g_nGaussianBlurValue, 40, on_GaussianBlur);
	on_GaussianBlur(g_nGaussianBlurValue, 0);

	//����qʱ�˳�
	while (char(waitKey(1)) != 'q') {};

	return 0;
}


//on_BoxFilter()����
static void on_BoxFilter(int, void*)
{
	boxFilter(g_srcImage, g_dstImage1, -1, Size(g_nBoxFilterValue + 1, g_nBoxFilterValue + 1));
	imshow("��<1>�����˲���", g_dstImage1);
}

//on_MeanBlur()����
static void on_MeanBlur(int,void*)
{
	blur(g_srcImage, g_dstImage2, Size(g_nMeanBlurValue + 1, g_nMeanBlurValue + 1), Point(-1, -1));
	imshow("��<2>��ֵ�˲���", g_dstImage2);

}

//on_GaussianBlur()����
static void on_GaussianBlur(int, void*)
{
	GaussianBlur(g_srcImage, g_dstImage3, Size(g_nGaussianBlurValue * 2 + 1, g_nGaussianBlurValue * 2 + 1), 0, 0);
	imshow("��<3>��˹�˲���", g_dstImage3);
}