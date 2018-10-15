#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<iostream>
using namespace cv;
using namespace std;

Mat srcImage, dstImage1, dstImage2, dstImage3, dstImage4, dstImage5;
int g_nBoxFilterVaule = 3;
int g_nMeanBlurVaule = 3;
int g_nGaussianBlurVaule = 3;
int g_nMediaBlurValue = 10;
int g_nBilateralFilterValue = 10;

static void BoxFilter(int, void *);
static void MeanBlur(int, void *);
static void _GaussianBlur(int, void *);
static void on_MeidaBlur(int, void *);
static void on_BilateralFilter(int, void *);

int main() {
	srcImage = imread("gu.jpg");
	dstImage1 = srcImage.clone();
	dstImage2 = srcImage.clone();
	dstImage3 = srcImage.clone();
	dstImage4 = srcImage.clone();
	dstImage5 = srcImage.clone();
	imshow("yuantu", srcImage);

	namedWindow("<1>fangkuang");
	createTrackbar("内核值:", "<1>fangkuang", &g_nBoxFilterVaule, 40, BoxFilter);
	BoxFilter(g_nBoxFilterVaule, 0);

	namedWindow("<2>junzhi");
	createTrackbar("内核值", "<2>junzhi", &g_nMeanBlurVaule, 40, MeanBlur);
	MeanBlur(g_nMeanBlurVaule, 0);

	namedWindow("<3>gaosi");
	createTrackbar("内核值", "<3>gaosi", &g_nGaussianBlurVaule, 40, _GaussianBlur);
	_GaussianBlur(g_nGaussianBlurVaule, 0);

	namedWindow("<4>zhongzhi");
	createTrackbar("内核值", "<4>zhongzhi", &g_nMediaBlurValue, 50, on_MeidaBlur);
	on_MeidaBlur(g_nMediaBlurValue, 0);

	namedWindow("<5>shuangbian");
	createTrackbar("内核值", "<5>shuangbian", &g_nBilateralFilterValue,50,on_BilateralFilter);
	on_BilateralFilter(g_nBilateralFilterValue, 0);
	
	cout << endl << "\t请调整滚动条观察效果" << "按下q退出`";

	while (char(waitKey(1)) != 'q') {}
	return 0;
}

static void BoxFilter(int, void *) {
	boxFilter(srcImage, dstImage1, -1, Size(g_nBoxFilterVaule + 1, g_nBoxFilterVaule + 1));
	imshow("<1>fangkuang", dstImage1);
}
static void MeanBlur(int, void *) {
	blur(srcImage, dstImage2, Size(g_nMeanBlurVaule + 1, g_nMeanBlurVaule + 1), Point(-1, -1));
	imshow("<2>junzhi", dstImage2);
}
static void _GaussianBlur(int, void *) {
	GaussianBlur(srcImage, dstImage3, Size(g_nGaussianBlurVaule * 2 + 1, g_nGaussianBlurVaule * 2 + 1), 0, 0);
	imshow("<3>gaosi", dstImage3);
}
static void on_MeidaBlur(int, void *) {
	medianBlur(srcImage, dstImage4, g_nMediaBlurValue * 2 + 1);
	imshow("<4>zhongzhi", dstImage4);
}
static void on_BilateralFilter(int, void *) {
	bilateralFilter(srcImage, dstImage5, g_nBilateralFilterValue, g_nBilateralFilterValue * 2, g_nBilateralFilterValue / 2);
	imshow("<5>shuangbian", dstImage5);
}





