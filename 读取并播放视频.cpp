#include<opencv2\opencv.hpp>
using namespace cv;
int main() {
	VideoCapture capture("�ʺ�1.0.avi");
	while (1)
	{
		Mat frame;
		capture >> frame;
		if (frame.empty())
			break;
		imshow("��ȡ��Ƶ", frame);
		waitKey(30);
	}
	return 0;
}