#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<iostream>
using namespace cv;
using namespace std;

Mat srcimage, dstimage;
int g_nTrackbarNumer = 0;
int g_nStructElementSize = 3;

void Process();
void TrackbarNumchange(int, void *);
void ElementSizeChange(int, void *);

int main() {
	srcimage = imread("xixi.jpg");;
	imshow("<1>yuanshitu", srcimage);
	namedWindow("<xiaoguotu>");
	Mat element = getStructuringElement(MORPH_RECT, Size(2 * g_nStructElementSize + 1, 2 * g_nStructElementSize + 1), Point(g_nStructElementSize, g_nStructElementSize));
	erode(srcimage, dstimage, element);
	imshow("<xiaoguotu>", dstimage);
	createTrackbar("≈Ú’Õ/∏Ø ¥", "<xiaoguotu>", &g_nStructElementSize, 1, TrackbarNumchange);
	createTrackbar("ƒ⁄∫À≥ﬂ¥Á", "<xiaoguotu>", &g_nStructElementSize, 21, ElementSizeChange);
	while (char(waitKey(1)) != 'q') {}
	return 0;
 }

void Process() {
	Mat element = getStructuringElement(MORPH_RECT, Size(2 * g_nStructElementSize + 1, 2 * g_nStructElementSize + 1), Point(g_nStructElementSize, g_nStructElementSize));
	if (g_nTrackbarNumer == 0) {
		erode(srcimage, dstimage, element);
	}
	else {
		dilate(srcimage, dstimage, element);
	}
	imshow("<xiaoguotu>", dstimage);
}
void TrackbarNumchange(int, void *) {
	Process();
}
void ElementSizeChange(int, void *) {
	Process();
}


