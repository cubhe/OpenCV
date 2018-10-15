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
	imshow("Ч��ͼ",dst);
	cout << area << "�����ر��ػ�\n";
}

int main() {
	g_srcimage = imread("xixi.jpg");
	g_srcimage.copyTo(g_dstimage);
	cvtColor(g_srcimage, g_grayimage, COLOR_BGR2GRAY);
	g_maskimage.create(g_srcimage.rows + 2, g_srcimage.cols + 2, CV_8UC1);
	namedWindow("Ч��ͼ", WINDOW_AUTOSIZE);
	createTrackbar("�������ֵ", "Ч��ͼ", &g_LowDifference, 255, 0);
	createTrackbar("�������ֵ", "Ч��ͼ", &g_UpDifference, 255, 0);

	setMouseCallback("Ч��ͼ", onMouse, 0);
	while (1) {
		imshow("Ч��ͼ", g_IsColor ? g_dstimage : g_grayimage);
		int c = waitKey(0);
		if ((c&255)==27)
		{
			cout << "�����˳�.......\n";
			break;
		}
		switch ((char)c)
		{
		case '1':
			if (g_IsColor)
			{
				cout << "����1�����£��л���ɫ/�Ҷ�ģʽ����ǰ����Ϊ������ɫ��Ϊ��ɫ\n";
				cvtColor(g_srcimage, g_grayimage, COLOR_BGR2GRAY);
				g_maskimage = Scalar::all(0);
				g_IsColor = false;
			}
			else
			{
				cout << "����1�����£��л���ɫ / �Ҷ�ģʽ����ǰ����Ϊ������ɫ��Ϊ��ɫ\n";
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
			cout << "����3�����£��ָ�ԭʼͼ��";
			g_srcimage.copyTo(g_dstimage);
			cvtColor(g_dstimage, g_grayimage, COLOR_BGR2GRAY);
			g_maskimage = Scalar::all(0);
			break;
		}
		case '4':
		{
			cout << "����3������,�ָ�ԭʼͼ��";
			g_srcimage.copyTo(g_dstimage);
			cvtColor(g_dstimage, g_grayimage, COLOR_BGR2GRAY);
			g_maskimage = Scalar::all(0);
			break;
		}
		case '5':
			cout << "����5�����£�ʹ�ý���,�̶���Χ����ˮ���";
			g_FillMode = 0;
			break;
		case '6':
			cout << "����6�����£�ʹ�ý��両����Χ����ˮ���";
			g_FillMode = 2;
			break;
		case '7':
			cout << "����7�����£�������־���ĵͰ�λʹ�ð�λ4λ������ģʽ";
			g_Connectivity = 4;
			break;
		case '8':
			cout << "����8�����£�������־���ĵͰ�λʹ�ð�λ8λ������ģʽ";
			g_Connectivity = 8;
			break;
		default:
			break;
		}
	}
	return 0;
}
