#include<opencv2\opencv.hpp>
using namespace cv;
int main() {
	VideoCapture capture("≤ ∫Á1.0.avi");
	while (1)
	{
		Mat frame;
		capture >> frame;
		if (frame.empty())
			break;
		imshow("∂¡»° ”∆µ", frame);
		waitKey(30);
	}
	return 0;
}