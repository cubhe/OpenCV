#include<opencv2\opencv.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
using namespace cv;
using namespace std;
#define WINDOW_NAME "�����򴰿ڡ�"
Mat g_srcimage, g_dstimage, g_tempimage;
int main() {
	g_srcimage = imread("aaa.jpg");
	if (!g_srcimage.data)
	{
		printf("��ȡsrcimage����~");
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
			printf(">��⵽��a�������£���ʼ���л��ڡ�pyrUp��������ͼƬ�Ŵ�ͼƬ�ߴ�*2\n");
			break;
		case 'w':
			resize(g_tempimage, g_dstimage, Size(g_tempimage.cols * 2, g_tempimage.rows * 2));
			printf(">��⵽��w�������£���ʼ���л��ڡ�resize��������ͼƬ�Ŵ�ͼƬ�ߴ�*2\n");
			break;
		case 'd':
			pyrDown(g_tempimage, g_dstimage, Size(g_tempimage.cols/2, g_tempimage.rows/2));
			printf(">��⵽��d�������£���ʼ���л��ڡ�pyrDown��������ͼƬ��С��ͼƬ�ߴ�/2\n");
			break;
		case 's':
			resize(g_tempimage, g_dstimage, Size(g_tempimage.cols/2, g_tempimage.rows/2));
			printf(">��⵽��d�������£���ʼ���л��ڡ�resize��������ͼƬ��С��ͼƬ�ߴ�/2\n");
			break;
		default:
			break;
		}
		imshow(WINDOW_NAME, g_dstimage);
		g_tempimage = g_dstimage;
	}
	return 0;
}