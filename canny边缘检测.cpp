#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
using namespace cv;
int main() {
	Mat srcimage = imread("������.jpg");
	imshow("��canny��Ե��⡿ԭͼ", srcimage);
	Mat edge,grayimage;
	cvtColor(srcimage, grayimage, CV_BGR2GRAY);
	blur(grayimage, edge, Size(3, 3));
	Canny(edge, edge, 3, 9, 3);
	imshow("��canny��Ե��⡿Ч��ͼ", edge);
	waitKey(0);
	return 0;
}