#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
using namespace cv;
int main() {
	Mat srcimage = imread("°¡°¡°¡.jpg");
	imshow("¡¾canny±ßÔµ¼ì²â¡¿Ô­Í¼", srcimage);
	Mat edge,grayimage;
	cvtColor(srcimage, grayimage, CV_BGR2GRAY);
	blur(grayimage, edge, Size(3, 3));
	Canny(edge, edge, 3, 9, 3);
	imshow("¡¾canny±ßÔµ¼ì²â¡¿Ð§¹ûÍ¼", edge);
	waitKey(0);
	return 0;
}