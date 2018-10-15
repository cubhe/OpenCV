#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;
#define WINDOW_NAME1 "[绘制图1]"
#define WINDOW_NAME2 "[绘制图2]"
#define WINDOW_WIDTH 600

void DrawEllipse(Mat img, double angle);
void DrawFilledCircle(Mat img, Point center);
void DrawLine(Mat img, Point start, Point end);
void DrawPolygon(Mat img);

int main(void) {
	//创建空的mat图像
	Mat atomimage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);
	Mat rookimage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);
	// draw ellippse
	DrawEllipse(atomimage, 90);
	DrawEllipse(atomimage, 0);
	DrawEllipse(atomimage, 45);
	DrawEllipse(atomimage, -45);
	//draw circle
	DrawFilledCircle(atomimage, Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2));
	//rectangle
	rectangle(rookimage,
		Point(0, 7 * WINDOW_WIDTH / 8),
		Point(WINDOW_WIDTH, WINDOW_WIDTH),
		Scalar(0, 255, 255),
		-1,
		8
	);
	//drawlines
	DrawLine(rookimage, Point(0, 15 * WINDOW_WIDTH / 16), Point(WINDOW_WIDTH, 15 * WINDOW_WIDTH / 16));
	DrawLine(rookimage, Point(WINDOW_WIDTH / 4, 7 * WINDOW_WIDTH / 8), Point(WINDOW_WIDTH / 4, WINDOW_WIDTH));
	DrawLine(rookimage, Point(WINDOW_WIDTH / 2, 7 * WINDOW_WIDTH / 8), Point(WINDOW_WIDTH / 2, WINDOW_WIDTH));
	DrawLine(rookimage, Point(3 * WINDOW_WIDTH / 4, 7*WINDOW_WIDTH / 8), Point(3 * WINDOW_WIDTH / 4, 7*WINDOW_WIDTH));

	//show image
	imshow(WINDOW_NAME1, atomimage);
	moveWindow(WINDOW_NAME1, 0, 200);
	imshow(WINDOW_NAME2, rookimage);
	moveWindow(WINDOW_NAME2, WINDOW_WIDTH, 200);
	waitKey(0);
	return 0;
}

void DrawEllipse(Mat img, double angle) {
	int thickness = 2;
	int linetype = 8;
	ellipse(img,
		Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2),
		Size(WINDOW_WIDTH / 4, WINDOW_WIDTH / 16),
		angle,
		0,
		360,
		Scalar(255, 129, 0),
		thickness,
		linetype
	);
}
void DrawFilledCircle(Mat img, Point center) {
	int thickness = -1;
	int linetype = 8;
	circle(img,
		center,
		WINDOW_WIDTH / 32,
		Scalar(0, 0, 255),
		thickness,
		linetype
	);

}
void DrawLine(Mat img, Point start, Point end) {
	int thickness = 2;
	int linetype = 8;
	line(
		img,
		start,
		end,
		Scalar(0, 0, 0 ),
		thickness,
		linetype
	);
}


