#include<opencv2\highgui\highgui.hpp>
#include<opencv2\core\core.hpp>
#include<iostream>
using namespace cv;
using namespace std;
bool MultiChannelBlending();
int main() {
	if (MultiChannelBlending())
	{
		cout << endl << "\n运行成功，的出了想要的图像：）";
	}
	waitKey(0);
	return 0;
}

bool MultiChannelBlending() {
	Mat srcimage1;
	vector<Mat> channels;
	Mat imageBlueChannel;
	srcimage1 = imread("bbb.jpg");
	if (!srcimage1.data)
		return 0;
	split(srcimage1, channels);
	imageBlueChannel = channels.at(0);
	merge(channels, srcimage1);
	namedWindow("<1>");
	imshow("<1>", srcimage1);
	return true;
}

//bool MultiChannelBlending() {
//	Mat srcimage1;
//	Mat srcimage2;
//	Mat Blue;
//	vector<Mat> channels;
//	Mat imageBlueChannel;
//	srcimage1 = imread("gu.jpg");
//	srcimage2 = imread("bbb.jpg");
//	split(srcimage1, channels);
//	imageBlueChannel = channels.at(0);
//	addWeighted(imageBlueChannel, 1.0, srcimage2, 0.5, 0, imageBlueChannel);
//	merge(channels, srcimage1);
//	namedWindow("<1>原图+蓝色通道");
//	imshow("<1>原图+蓝色通道", srcimage1);
//	return true;
//}


