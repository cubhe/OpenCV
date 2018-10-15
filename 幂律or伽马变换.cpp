/*2017 12 2*/

#include<opencv2\opencv.hpp>
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<iostream>
using namespace cv;
using namespace std;
int main() {
	Mat srcImage = imread("1.jpg", 0);
	imshow("aa", srcImage);
	int rownumber = srcImage.rows;
	int colnumber = srcImage.cols*srcImage.channels();
	for (size_t i = 0; i < rownumber; i++){
		uchar * data = srcImage.ptr<uchar>(i);
		for (size_t j = 0; j < colnumber; j++){
			float temp = pow(data[j] / 255.0,0.5)* 255;
			data[j] = temp;
		}
	}
	cout << "m=" << endl << " " << srcImage << endl << endl;
	imshow("ab", srcImage);
	waitKey(0);
	return 0;
}