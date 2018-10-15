#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<iostream>
using namespace cv;
using namespace std;
Mat g_srcimage, g_dstimage, g_grayimage, g_maskimage;
int g_FillMode = 1;
int g_LowDifference = 20, g_UpDifference = 20;
int g_Connectivity = 4;
int g_IsColor = true;
int g_UseMask = false;
int g_NewMaskVal = 255;

static void onMouse(int event, int x, int y, int, void*) {
	if (event != EVENT_LBUTTONDOWN)
		return;
	Point seed = Point(x, y);
	int LowDifference = g_FillMode == 0 ? 0 : g_LowDifference;
	int UpDifference = g_FillMode == 0 ? 1 : g_UpDifference;
	int flags = g_Connectivity + (g_NewMaskVal << 8) + (g_FillMode == 1 ? FLOODFILL_FIXED_RANGE : 0);
	int b = (unsigned)theRNG() & 255;
	int g = (unsigned)theRNG() & 255;
	int r = (unsigned)theRNG() & 255;
	Rect ccomp;
	Scalar newVal = g_IsColor ? Scalar(b, g, r) : Scalar(r*0.299 + g*0.587 + b*0.114);
	Mat dst = g_IsColor ? g_dstimage : g_grayimage;
	int area;
	if (g_UseMask)
	{
		threshold(g_maskimage, g_maskimage, 1, 128, THRESH_BINARY);
		area = floodFill(dst, g_maskimage, seed, newVal, &ccomp, Scalar(LowDifference, LowDifference, LowDifference), Scalar(UpDifference, UpDifference, UpDifference), flags);
		imshow("mask", g_dstimage);
	}
	else
	{
		area = floodFill(dst, seed, newVal, &ccomp, Scalar(LowDifference, LowDifference, LowDifference), Scalar(UpDifference, UpDifference, UpDifference), flags);
	}
	imshow("效果图",dst);
	cout << area << "个像素被重绘\n";
}

int main() {
	g_srcimage = imread("xixi.jpg");
	g_srcimage.copyTo(g_dstimage);
	cvtColor(g_srcimage, g_grayimage, COLOR_BGR2GRAY);
	g_maskimage.create(g_srcimage.rows + 2, g_srcimage.cols + 2, CV_8UC1);
	namedWindow("效果图", WINDOW_AUTOSIZE);
	createTrackbar("负差最大值", "效果图", &g_LowDifference, 255, 0);
	createTrackbar("正差最大值", "效果图", &g_UpDifference, 255, 0);

	setMouseCallback("效果图", onMouse, 0);
	while (1) {
		imshow("效果图", g_IsColor ? g_dstimage : g_grayimage);
		int c = waitKey(0);
		if ((c&255)==27)
		{
			cout << "程序退出.......\n";
			break;
		}
		switch ((char)c)
		{
		case '1':
			if (g_IsColor)
			{
				cout << "键盘1被按下，切换彩色/灰度模式，当前操作为：将彩色换为灰色\n";
				cvtColor(g_srcimage, g_grayimage, COLOR_BGR2GRAY);
				g_maskimage = Scalar::all(0);
				g_IsColor = false;
			}
			else
			{
				cout << "键盘1被按下，切换彩色 / 灰度模式，当前操作为：将灰色换为彩色\n";
				g_srcimage.copyTo(g_dstimage);
				g_maskimage = Scalar::all(0);
				g_IsColor = true;
			}
			break;
		case '2':
		{
			if (g_UseMask)
			{
				destroyWindow("mask");
				g_UseMask = false;
			}
			else
			{
				namedWindow("mask", 0);
				g_maskimage = Scalar::all(0);
				imshow("mask", g_maskimage);
				g_UseMask = true;
			}
			break;
		}
		case '3':
		{
			cout << "按键3被按下，恢复原始图像";
			g_srcimage.copyTo(g_dstimage);
			cvtColor(g_dstimage, g_grayimage, COLOR_BGR2GRAY);
			g_maskimage = Scalar::all(0);
			break;
		}
		case '4':
		{
			cout << "按键3被按下,恢复原始图像";
			g_srcimage.copyTo(g_dstimage);
			cvtColor(g_dstimage, g_grayimage, COLOR_BGR2GRAY);
			g_maskimage = Scalar::all(0);
			break;
		}
		case '5':
			cout << "按键5被按下，使用渐变,固定范围的漫水填充";
			g_FillMode = 0;
			break;
		case '6':
			cout << "按键6被按下，使用渐变浮动范围的漫水填充";
			g_FillMode = 2;
			break;
		case '7':
			cout << "按键7被按下，操作标志符的低八位使用八位4位的连接模式";
			g_Connectivity = 4;
			break;
		case '8':
			cout << "按键8被按下，操作标志符的低八位使用八位8位的连接模式";
			g_Connectivity = 8;
			break;
		default:
			break;
		}
	}
	return 0;
}
