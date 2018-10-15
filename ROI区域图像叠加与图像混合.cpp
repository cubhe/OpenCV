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
		cout << endl << "运行成功，得出了你想要的图像~~：)";
	}
	waitKey(0);
	return 0;
}

bool ROI_AddImage() {
	Mat srcimage1 = imread("aaa.jpg");
	Mat logoImage = imread("bbb1.jpg");
	if (!srcimage1.data&&!logoImage.data)
	{
		printf("读取错误~\n");
		return false;
	}
	Mat imageROI = srcimage1(Rect(0, 0, logoImage.cols, logoImage.rows));
	//加载掩膜
	Mat mask = imread("bbb1.jpg", 0);
	//将掩膜复制到ROI
	logoImage.copyTo(imageROI, mask);
	namedWindow("<1>利用ROI实现图形叠加");
	imshow("<1>利用ROI实现图形叠加", srcimage1);
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
	namedWindow("<2>线性混合【效果图】");
	imshow("<2>线性混合【效果图】", dstimage);
	waitKey(0);
	return true;
}
bool ROI_LInearBlending() {
	Mat srcimage = imread("bbb.jpg",1);
	Mat her = imread("gu.jpg");
	Mat imageROI = srcimage(Rect(0, 0, her.cols, her.rows));
	addWeighted(imageROI, 0.5, her, 0.3, 0.0, imageROI);
	namedWindow("<3>区域线性混合图像");
	imshow("<3>区域线性混合图像", srcimage);
	waitKey(0);
	return true;

}


