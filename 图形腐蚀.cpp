#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
using namespace cv;
int main() {
	Mat srcimage = imread("啊啊啊.jpg");
	imshow("【终于成功了啊QAQ】原图", srcimage);
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat dstimage;
	erode(srcimage, dstimage, element);
	imshow("腐蚀操作效果图", dstimage);
	waitKey(0);
	return 0;
}