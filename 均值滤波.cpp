#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
using namespace cv;
int main() {
	Mat srcimage = imread("������.jpg");
	imshow("����ֵ�˲���ԭͼ", srcimage);
	Mat dstimage;
	blur(srcimage, dstimage, Size(7, 7));
	imshow("����ֵ�˲���Ч��ͼ", dstimage);
	waitKey(0);
	return 0;
}