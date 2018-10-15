#include<opencv2\opencv.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
using namespace cv;
using namespace std;
#define WINDOW_NAME "【程序窗口】"
int g_ThresholdValue = 100;
int g_ThresholdType = 3;
Mat g_srcimage, g_dstimage, g_grayimage;
void on_Threshold(int, void*);
int main() {
	g_srcimage = imread("aaa.jpg");
	cvtColor(g_srcimage, g_grayimage, COLOR_RGB2GRAY);
	namedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);
	createTrackbar("模式", WINDOW_NAME,&g_ThresholdType, 4, on_Threshold);
	createTrackbar("参数值", WINDOW_NAME, &g_ThresholdValue, 255, on_Threshold);
	on_Threshold(0, 0);
	while (1)
	{
		int key;
		key = waitKey(9);
		if ((char)key == 27)
			break;
	}
	return 0;
}

void on_Threshold(int, void*) {
	threshold(g_grayimage, g_dstimage, g_ThresholdValue, 255, g_ThresholdType);
	imshow(WINDOW_NAME, g_dstimage);
}
