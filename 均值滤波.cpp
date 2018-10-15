#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
using namespace cv;
int main() {
	Mat srcimage = imread("啊啊啊.jpg");
	imshow("【均值滤波】原图", srcimage);
	Mat dstimage;
	blur(srcimage, dstimage, Size(7, 7));
	imshow("【均值滤波】效果图", dstimage);
	waitKey(0);
	return 0;
}