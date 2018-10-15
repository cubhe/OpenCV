/*2017 12 2*/
#include<opencv2\opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
int main() {
	Mat srcImage = imread("1.jpg", 0);
	imshow("aa", srcImage);
	int rownumber = srcImage.rows;
	int colnumber = srcImage.cols*srcImage.channels();
	/*第一种方法*/
	for (size_t i = 1; i < rownumber-1; i++){
		/*三行的行指针*/
		uchar * data0 = srcImage.ptr<uchar>(i-1);		
		uchar * data1 = srcImage.ptr<uchar>(i);
		uchar * data2 = srcImage.ptr<uchar>(i+1);

		for (size_t j = 1; j < colnumber-1; j++){
			float temp = (data0[j - 1] + data0[j] + data0[j + 1] + data1[j - 1] + data1[j] + data1[j + 1] + data2[j - 1] + data2[j] + data2[j + 1]) / 9;
			data1[j] = temp;
		}
	}
	/*第二种方法*/
	for (size_t i = 1; i < rownumber-1; i++)
	{
		for (size_t j = 1; j < colnumber-1; j++)
		{
			srcImage.at<uchar>(i, j) = (srcImage.at<uchar>(i-1, j - 1) + srcImage.at<uchar>(i-1, j) + srcImage.at<uchar>(i-1, j + 1) + srcImage.at<uchar>(i, j-1)+ srcImage.at<uchar>(i, j)+srcImage.at<uchar>(i, j+1)+ srcImage.at<uchar>(i+1, j - 1) + srcImage.at<uchar>(i+1, j) + srcImage.at<uchar>(i+1, j + 1))/9;
		}
	}
	//cout << "m=" << endl << " " << srcImage << endl << endl;//输出图像像素值
	imshow("ab", srcImage);
	waitKey(0);
	return 0;
}
