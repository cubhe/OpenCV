#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
using namespace cv;
using namespace std;
Mat srcimage, dstimage;
int ElementShape = MORPH_RECT;

int MaxIterationNum = 10;
int OpenCloseNum = 0;
int ErodeDilateNum = 0;
int TopBlackNum = 0;

static void OpenClose(int, void *);
static void ErodeDilate(int, void *);
static void TopBlackHat(int, void *);

int main() {
	srcimage = imread("bbb.jpg");
	imshow("<Ô­Ê¼Í¼>", srcimage);

	namedWindow("<¿ªÔËËã/±ÕÔËËã>");
	namedWindow("<¸¯Ê´/ÅòÕÍ>");
	namedWindow("<ºÚÃ±/¶¥Ã±>");

	OpenCloseNum = 9;
	ErodeDilateNum = 9;
	TopBlackNum = 2;

	createTrackbar("µü´úÖµ", "<¿ªÔËËã/±ÕÔËËã>", &OpenCloseNum, MaxIterationNum * 2 + 1, OpenClose);
	createTrackbar("µü´úÖµ", "<¸¯Ê´/ÅòÕÍ>", &OpenCloseNum, MaxIterationNum * 2 + 1, ErodeDilate);
	createTrackbar("µü´úÖµ", "<ºÚÃ±/¶¥Ã±>", &OpenCloseNum, MaxIterationNum * 2 + 1, TopBlackHat);

	while (1) {
		int c;
		OpenClose(OpenCloseNum, 0);
		ErodeDilate(ErodeDilateNum, 0);
		TopBlackHat(TopBlackNum, 0);
		c = waitKey(0);
		if (char(c) == 'q' || (char)c == 27)
			break;
		if ((char)c == 49)
			ElementShape = MORPH_ELLIPSE;
		else if ((char)c == 50)
			ElementShape = MORPH_RECT;
		else if ((char)c == 51)
			ElementShape = MORPH_CROSS;
		else if ((char)c == ' ')
			ElementShape = (ElementShape + 1) % 3;	
	}
	return 0;
}

static void OpenClose(int, void *) {
	int offset = OpenCloseNum - MaxIterationNum;
	int Absolute_offset = offset > 0 ? offset : -offset;
	Mat element = getStructuringElement(ElementShape, Size(Absolute_offset * 2 + 1, Absolute_offset * 2 + 1), Point(Absolute_offset, Absolute_offset));
	if (offset<0)
	{
		morphologyEx(srcimage, dstimage, MORPH_OPEN, element);
	}
	else
	{
		morphologyEx(srcimage, dstimage, MORPH_CLOSE, element);
	}
	imshow("<¿ªÔËËã/±ÕÔËËã>",dstimage);
}
static void ErodeDilate(int, void *) {
	int offset = ErodeDilateNum - MaxIterationNum;
	int Absolute_offset = offset > 0 ? offset : -offset;
	Mat element = getStructuringElement(ElementShape, Size(Absolute_offset * 2 + 1, Absolute_offset * 2 + 1), Point(Absolute_offset, Absolute_offset));
	if (offset < 0)
		erode(srcimage, dstimage, element);
	else
		dilate(srcimage, dstimage, element);
		imshow("<¸¯Ê´/ÅòÕÍ>", dstimage);
}
static void TopBlackHat(int, void *) {
	int offset = TopBlackNum - MaxIterationNum;
	int Absolute_offset = offset > 0 ? offset : -offset;
	Mat element = getStructuringElement(ElementShape, Size(Absolute_offset * 2 + 1, Absolute_offset * 2 + 1), Point(Absolute_offset, Absolute_offset));
	if (offset < 0)
		morphologyEx(srcimage, dstimage, MORPH_TOPHAT, element);
	else
		morphologyEx(srcimage, dstimage, MORPH_BLACKHAT, element);
	imshow("<ºÚÃ±/¶¥Ã±>", dstimage);
}

