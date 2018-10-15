#include<opencv2\opencv.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
using namespace cv;
using namespace std;
#define WINDOW_NAME "【程序窗口】"
Mat g_srcimage, g_dstimage, g_tempimage;
int main() {
	g_srcimage = imread("aaa.jpg");
	if (!g_srcimage.data)
	{
		printf("读取srcimage错误~");
		return false;
	}
	namedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);
	imshow(WINDOW_NAME, g_srcimage);
	g_tempimage = g_srcimage;
	g_dstimage = g_tempimage;
	int key = 0;
	while (1)
	{
		key = waitKey(9);
		switch (key)
		{
		case 27:
			return 0;
			break;
		case 'q':
			return 0;
			break;
		case 'a':
			pyrUp(g_tempimage, g_dstimage, Size(g_tempimage.cols * 2, g_tempimage.rows * 2));
			printf(">检测到【a】被按下，开始进行基于【pyrUp】函数的图片放大：图片尺寸*2\n");
			break;
		case 'w':
			resize(g_tempimage, g_dstimage, Size(g_tempimage.cols * 2, g_tempimage.rows * 2));
			printf(">检测到【w】被按下，开始进行基于【resize】函数的图片放大：图片尺寸*2\n");
			break;
		case 'd':
			pyrDown(g_tempimage, g_dstimage, Size(g_tempimage.cols/2, g_tempimage.rows/2));
			printf(">检测到【d】被按下，开始进行基于【pyrDown】函数的图片缩小：图片尺寸/2\n");
			break;
		case 's':
			resize(g_tempimage, g_dstimage, Size(g_tempimage.cols/2, g_tempimage.rows/2));
			printf(">检测到【d】被按下，开始进行基于【resize】函数的图片缩小：图片尺寸/2\n");
			break;
		default:
			break;
		}
		imshow(WINDOW_NAME, g_dstimage);
		g_tempimage = g_dstimage;
	}
	return 0;
}