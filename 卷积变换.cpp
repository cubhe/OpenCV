/*2017 12 2*/
#include<opencv2\opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
float juanji(uchar a[][3],int size[][3]);
int main() {
	Mat srcImage = imread("1.jpg", 0);
	Mat dstImage;
	srcImage.copyTo(dstImage);
	int rownumber = srcImage.rows;
	int colnumber = srcImage.cols*srcImage.channels();
	/*第一种方法*/
	for (size_t i = 1; i < rownumber - 1; i++) {
		/*三行的行指针*/
		uchar * data0 = srcImage.ptr<uchar>(i - 1);
		uchar * data1 = srcImage.ptr<uchar>(i);
		uchar * data2 = srcImage.ptr<uchar>(i + 1);
		uchar * data = dstImage.ptr<uchar>(i);
		int size[3][3] = { 1,2,1, 2,4,2, 1,2,1 };
		for (size_t j = 1; j < colnumber - 1; j++) {
			uchar a[3][3] = { data0[j - 1] , data0[j] , data0[j + 1] , data1[j - 1] ,data1[j] , data1[j + 1], data2[j - 1], data2[j] , data2[j + 1] };
			
			//float temp = (data0[j - 1] + data0[j] + data0[j + 1] + data1[j - 1] + data1[j] + data1[j + 1] + data2[j - 1] + data2[j] + data2[j + 1]) / 9;
			data[j] = juanji(a, size);
		}
	}
	/*第二种方法
	for (size_t i = 1; i < rownumber-1; i++)
	{
		for (size_t j = 1; j < colnumber-1; j++)
		{
			srcImage.at<uchar>(i, j) = (srcImage.at<uchar>(i-1, j - 1) + srcImage.at<uchar>(i-1, j) + srcImage.at<uchar>(i-1, j + 1) + srcImage.at<uchar>(i, j-1)+ srcImage.at<uchar>(i, j)+srcImage.at<uchar>(i, j+1)+ srcImage.at<uchar>(i+1, j - 1) + srcImage.at<uchar>(i+1, j) + srcImage.at<uchar>(i+1, j + 1))/9;
		}
	}*/
	//cout << "m=" << endl << " " << srcImage << endl << endl;//输出图像像素值
	imshow("aa", srcImage);
	imshow("ab", dstImage);
	waitKey(0);
	return 0;
}
float juanji(uchar a[][3], int size[][3])
{
	float sum = 0;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			sum += a[i][j] * size[2 - i][2 - j];
		}
	}
	float num = 0;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			num += size[i][j];
		}
	}
	return sum / num;
}