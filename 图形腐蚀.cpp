#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
using namespace cv;
int main() {
	Mat srcimage = imread("������.jpg");
	imshow("�����ڳɹ��˰�QAQ��ԭͼ", srcimage);
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat dstimage;
	erode(srcimage, dstimage, element);
	imshow("��ʴ����Ч��ͼ", dstimage);
	waitKey(0);
	return 0;
}