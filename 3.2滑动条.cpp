//两个jpg的像素要相同！！
//搞了好久都没成功
//还好我长得帅不然真不知道该怎么办

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#define WINDOW_NAME "【线性混合示例】"
using namespace cv;

const int g_nMaxAlphaValue = 100;
int g_nAlphaValueSlider;
double g_dAlphaValue;
double g_dBetaValue;

Mat g_srcImage1;
Mat g_srcImage2;
Mat g_srcImage;

void on_trackbar(int, void*)
{
	g_dAlphaValue = (double)g_nAlphaValueSlider / g_nMaxAlphaValue;
	g_dBetaValue = (1.0 - g_dAlphaValue);
	addWeighted(g_srcImage1, g_dAlphaValue, g_srcImage2, g_dBetaValue,0.0,g_srcImage);
	imshow(WINDOW_NAME, g_srcImage);
}
int main() {
	g_srcImage1 = imread("aaa.jpg");
	g_srcImage2 = imread("bbb.jpg");
	g_nAlphaValueSlider = 70;
	namedWindow(WINDOW_NAME, 1);
	char TrackbarName[50];
	sprintf(TrackbarName, "透明值 %d", g_nMaxAlphaValue);
	createTrackbar(TrackbarName, WINDOW_NAME, &g_nAlphaValueSlider, g_nMaxAlphaValue, on_trackbar);
	//on_trackbar(g_nAlphaValueSlider, 0);
	waitKey(0);
	return 0;
}
