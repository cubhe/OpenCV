/*2017 12 6 */
#include<stdio.h>
#include<opencv2\opencv.hpp>
using namespace cv;
int main() {
	Mat srcimage = imread("IMG_1967.jpg", 0);
	double f = 600.0 / srcimage.cols;
	resize(srcimage, srcimage, Size(0, 0), f, f);
	if (!srcimage.data)
		printf("该目录下没有此图片");
	imshow("新垣结衣", srcimage);
	int m = getOptimalDFTSize(srcimage.rows);
	int n = getOptimalDFTSize(srcimage.cols);
	Mat Big;
	copyMakeBorder(srcimage, Big, 0, m - srcimage.rows, 0, n - srcimage.cols, BORDER_CONSTANT, Scalar::all(0));
	Mat planes[] = { Mat_<float>(Big),Mat::zeros(Big.size(),CV_32F)};
	Mat complex1;
	merge(planes, 2, complex1);
	dft(complex1, complex1);
	split(complex1, planes);
	magnitude(planes[0], planes[1], planes[0]);
	Mat magnituded = planes[0];
	magnituded += Scalar::all(1);
	log(magnituded, magnituded);
	magnituded = magnituded(Rect(0, 0, magnituded.cols&-2, magnituded.rows & -2));
	/*交换象限*/
	int x = magnituded.cols / 2;
	int y = magnituded.rows / 2;
	Mat q0(magnituded, Rect(0, 0, x, y));
	Mat q1(magnituded, Rect(x, 0, x, y));
	Mat q2(magnituded, Rect(0, y, x, y));
	Mat q3(magnituded, Rect(x, y, x, y));
	Mat temp;
	q0.copyTo(temp);
	q3.copyTo(q0);
	temp.copyTo(q3);
	q1.copyTo(temp);
	q2.copyTo(q1);
	temp.copyTo(q2);
	normalize(magnituded, magnituded, 0, 1, NORM_MINMAX);
	imshow("频域下的新垣结衣", magnituded);
	waitKey(0);
	return 0;
}