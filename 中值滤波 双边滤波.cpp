#include<opencv2\highgui\highgui.hpp>
#include<opencv2\core\core.hpp>
#include<opencv2\imgproc\imgproc.hpp>
using namespace cv;
int main() {
	Mat image = imread("gu.jpg");
	imshow("yuantu", image);

	Mat outone;
	medianBlur(image, outone, 7);
	imshow("xaioguotu", outone);

	Mat outtwo;
	bilateralFilter(image, outtwo, 25, 25 * 2, 25 / 2);
	imshow("xiaoguotu2", outtwo);
	waitKey(0);
	return 0;
}