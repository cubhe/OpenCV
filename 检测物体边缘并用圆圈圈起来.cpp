#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
#define WINDOWNAME1 "原始窗口"
#define WINDOWNAME2 "效果图窗口"
Mat g_srcimage;
Mat g_grayimage;
int g_nThresh = 27;
int g_nMaxThresh = 255;
RNG g_rng(12345);
void on_ContoursChange(int, void*);
int main() {
	system("color 1A");
	g_srcimage = imread("3.jpg", 1);
	cvtColor(g_srcimage, g_grayimage, COLOR_BGR2GRAY);
	blur(g_grayimage, g_grayimage, Size(3, 3));

	//erode(g_grayimage, g_grayimage, getStructuringElement(MORPH_RECT, Size(15, 15)));
	//dilate(g_grayimage, g_grayimage, getStructuringElement(MORPH_RECT, Size(15, 15)));
	//namedWindow(WINDOWNAME1, WINDOW_NORMAL);
	morphologyEx(g_grayimage, g_grayimage, MORPH_GRADIENT, getStructuringElement(MORPH_RECT, Size(15, 15)));
	imshow(WINDOWNAME1, g_srcimage);
	//namedWindow("腐蚀", WINDOW_NORMAL);

	imshow("腐蚀", g_grayimage);
	createTrackbar("阈值：", WINDOWNAME1, &g_nThresh, g_nMaxThresh, on_ContoursChange);
	on_ContoursChange(0, 0);
	waitKey(0);
	return 0;
}
void 	on_ContoursChange(int, void*) {
	Mat threshold_output;
	std::vector<  vector<Point>  >  contours;
	std::vector<Vec4i>  hierarchy;
	threshold(g_grayimage, threshold_output, g_nThresh, 255, THRESH_BINARY);
	imshow("fazhi", threshold_output);
	findContours(threshold_output, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));
	vector<vector<Point>> contours_poly(contours.size());
	vector<Rect>boundRect(contours.size());
	vector<Point2f>center(contours.size());
	vector<float>radius(contours.size());
	for (unsigned int i = 0; i < contours.size(); i++)
	{
		approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
		boundRect[i] = boundingRect(Mat(contours_poly[i]));
		minEnclosingCircle(contours_poly[i], center[i], radius[i]);
	}
	Mat drawing = Mat::zeros(threshold_output.size(), CV_8UC3);
	for (size_t i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(g_rng.uniform(0, 255), g_rng.uniform(0, 255), g_rng.uniform(0, 255));
		drawContours(drawing, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point());
		//rectangle(drawing, boundRect[i].tl(), (int)radius[i], color, 2, 8, 0);
		circle(drawing, center[i], (int)radius[i], color, 2, 8, 0);
	}
	namedWindow(WINDOWNAME2, WINDOW_NORMAL);
	imshow(WINDOWNAME2, drawing);
}
