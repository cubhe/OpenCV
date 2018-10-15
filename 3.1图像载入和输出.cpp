#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;
int main() {
	Mat image = imread("aaa.jpg");
	namedWindow("xiniu");
	imshow("xiniu", image);

	Mat logo = imread("bbb.jpg");
	namedWindow("chuan");
	imshow("chuan", logo);

	imwrite("from imwrite.jpg", image);
	waitKey(0);
	return 0;
}
