#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<stdio.h>
using namespace cv;
using namespace std;
#define WINDOWNAME1 "原始窗口"
#define WINDOWNAME2 "效果图窗口"
Mat g_srcimage;
Mat g_grayimage;
int g_nThresh = 117;
int g_nMaxThresh = 255;
int g_nElementSize = 10;
RNG g_rng(12345);
void on_ContoursChange(int, void*);
void on_ElementSizeChange(int, void*);
int main() {
	system("color 80");
	g_srcimage = imread("6.jpg", 1);
	imshow(WINDOWNAME1, g_srcimage);
	//灰度图
	cvtColor(g_srcimage, g_grayimage, COLOR_BGR2GRAY);
	//形态学梯度 这一步很关键
	morphologyEx(g_grayimage, g_grayimage, MORPH_GRADIENT, getStructuringElement(MORPH_RECT, Size(20, 20)));
	imshow("2", g_grayimage);
	//中值滤波 可以换其他的滤波 感觉每种都不一样
	medianBlur(g_grayimage, g_grayimage, 7);
	//imshow("3", g_grayimage);
	//createTrackbar("滤波", WINDOWNAME1, &g_nElementSize, 21, on_ElementSizeChange);
	createTrackbar("阈值：", WINDOWNAME1, &g_nThresh, g_nMaxThresh, on_ContoursChange);
	on_ContoursChange(0, 0);
	waitKey(0);
	return 0;
}
void 	on_ContoursChange(int, void*) {
	Mat threshold_output;
	std::vector<  vector<Point>  >  contours;
	std::vector<Vec4i>  hierarchy;
	//阈值
 	threshold(g_grayimage, threshold_output, g_nThresh, 255, THRESH_BINARY);
	//morphologyEx(g_grayimage, g_grayimage, MORPH_GRADIENT, getStructuringElement(MORPH_RECT, Size(20, 20)));
	//imshow("fazhi", threshold_output);
	findContours(threshold_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
	vector<vector<Point>> contours_poly(contours.size());
	vector<Rect>boundRect(contours.size());
	vector<Point2f>center(contours.size());
	vector<float>radius(contours.size());
	for (unsigned int i = 0; i < contours.size(); i++){
		approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
		boundRect[i] = boundingRect(Mat(contours_poly[i]));
		minEnclosingCircle(contours_poly[i], center[i], radius[i]);
	}
	Mat drawing = Mat::zeros(threshold_output.size(), CV_8UC3);
	for (size_t i = 0; i < contours.size(); i++){
		if (contourArea(contours[i]) > 7500) {
			Scalar color = Scalar(g_rng.uniform(0, 255), g_rng.uniform(0, 255), g_rng.uniform(0, 255));
			drawContours(drawing, contours_poly, i, color, -1, 8, vector<Vec4i>(), 0, Point());
			//rectangle(drawing, boundRect[i].tl(), (int)radius[i], color, 2, 8, 0);
			RotatedRect box = minAreaRect(contours[i]);
			Point2f vertex[4];
			box.points(vertex);
			for (size_t j = 0; j < 4; j++){
				line(drawing, vertex[j], vertex[(j + 1) % 4], color, 2, LINE_AA);
			} 
			circle(drawing, center[i], (int)radius[i], color, 2, 8, 0);
			cout << "【二维点】" << endl << center[i] << endl;
			printf("【角度】%lf\n", box.angle);
		}
	}
	namedWindow(WINDOWNAME2, WINDOW_AUTOSIZE);
	imshow(WINDOWNAME2, drawing);
}
void on_ElementSizeChange(int, void*) {
	int i = g_nElementSize * 2 + 1;
	bilateralFilter(g_grayimage, g_grayimage, i, i * 2, i / 2);
	imshow("lvbo", g_grayimage);
}