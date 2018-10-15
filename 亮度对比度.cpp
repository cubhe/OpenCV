#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<iostream>
using namespace cv;
using namespace std;
static void on_ContrastAndBright(int, void *);

int g_ContrastValue;
int g_BrightValue;
Mat srcimage, dstimage;

int main() {
	srcimage = imread("gu.jpg");
    dstimage = Mat::zeros(srcimage.size(), srcimage.type());
	g_ContrastValue = 80;
	g_BrightValue = 80;
	namedWindow("效果窗口图", 1);
	createTrackbar("对比度：", "效果窗口图", &g_ContrastValue, 300, on_ContrastAndBright);
	createTrackbar("亮 度：", "效果窗口图", &g_ContrastValue,200, on_ContrastAndBright);
	on_ContrastAndBright(g_BrightValue, 0);
	on_ContrastAndBright(g_ContrastValue, 0);
	while (char(waitKey(1)) != 'q') {}
	return 0;
}

static void on_ContrastAndBright(int, void *)
{
	namedWindow("yuanshitu",1);
	//dstimage(i, j) = a*srcimage(i, j) + b;
	for (size_t y = 0; y < srcimage.rows; y++)
	{
		for (size_t x = 0; x < srcimage.cols; x++)
		{
			for (size_t c = 0;  c < 3;  c++)
			{
				dstimage.at<Vec3b>(y, x)[c] =
					saturate_cast<uchar>((g_ContrastValue*0.01)*(srcimage.at<Vec3b>(y, x)[c]) + g_BrightValue);
			}
		}
	}
	imshow("yuanshitu", srcimage);
	imshow("效果窗口图", dstimage);

}
