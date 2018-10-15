#include<opencv2\opencv.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<iostream>
using namespace cv;
using namespace std;

bool ROI_AddImage();
bool LinearBlending();
bool ROI_LInearBlending();

int main() {
	system("color 6E");
	if (ROI_AddImage()&& LinearBlending()&& ROI_LInearBlending())
	{
		cout << endl << "���гɹ����ó�������Ҫ��ͼ��~~��)";
	}
	waitKey(0);
	return 0;
}

bool ROI_AddImage() {
	Mat srcimage1 = imread("aaa.jpg");
	Mat logoImage = imread("bbb1.jpg");
	if (!srcimage1.data&&!logoImage.data)
	{
		printf("��ȡ����~\n");
		return false;
	}
	Mat imageROI = srcimage1(Rect(0, 0, logoImage.cols, logoImage.rows));
	//������Ĥ
	Mat mask = imread("bbb1.jpg", 0);
	//����Ĥ���Ƶ�ROI
	logoImage.copyTo(imageROI, mask);
	namedWindow("<1>����ROIʵ��ͼ�ε���");
	imshow("<1>����ROIʵ��ͼ�ε���", srcimage1);
	waitKey(0);
	return true;
}
bool LinearBlending() {
	double alghavalue = 0.5;
	double betavalue;
	Mat srcimage1, srcimage2, dstimage;
	srcimage1 = imread("aaa.jpg");
	srcimage2 = imread("bbb.jpg");
	betavalue = 1.0 - alghavalue;
	addWeighted(srcimage1, alghavalue, srcimage2, betavalue, 0.0, dstimage);
	namedWindow("<2>���Ի�ϡ�Ч��ͼ��");
	imshow("<2>���Ի�ϡ�Ч��ͼ��", dstimage);
	waitKey(0);
	return true;
}
bool ROI_LInearBlending() {
	Mat srcimage = imread("bbb.jpg",1);
	Mat her = imread("gu.jpg");
	Mat imageROI = srcimage(Rect(0, 0, her.cols, her.rows));
	addWeighted(imageROI, 0.5, her, 0.3, 0.0, imageROI);
	namedWindow("<3>�������Ի��ͼ��");
	imshow("<3>�������Ի��ͼ��", srcimage);
	waitKey(0);
	return true;

}


