#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>
using namespace cv;
using namespace std;

void colorReduce1(Mat& inputimage, Mat & outputimage, int div);
void colorReduce2(Mat& inputimage, Mat & outputimage, int div);
void colorReduce3(Mat& inputimage, Mat & outputimage, int div);

int main() {

	//创建原始图
	Mat srcimage = imread("aaa.jpg");
	imshow("原始图像", srcimage);

	//按原始图的参数规格创建效果图
	Mat dstimage;
	dstimage.create(srcimage.rows, srcimage.cols, srcimage.type());

	//记录起始时间
	double time0 = static_cast<double>(getTickCount());

	//调用颜色缩减函数
	colorReduce3(srcimage, dstimage, 32);

	//计算运行时间并退出
	time0 = ((double)getTickCount() - time0) / getTickFrequency();
	cout << "此方法运行时间为：" << time0 << "秒" << endl;

	//显示效果图
	imshow("效果图", dstimage);
	waitKey(0);
}

void colorReduce1(Mat& inputimage, Mat& outputimage, int div)
{
	outputimage = inputimage.clone();
	int rownuber = outputimage.rows;
	int colnumber = outputimage.cols*outputimage.channels();
	for (size_t i = 0; i < rownuber; i++)
	{
		uchar *data = outputimage.ptr<uchar>(i);
		for (size_t j = 0; j < colnumber; j++)
		{
			//开始处理每个像素
			data[j] = data[j] / div*div + div / 2;

		}
	}
}
void colorReduce2(Mat& inputimage, Mat & outputimage, int div) {
	outputimage = inputimage.clone();
	//获取迭代器
	Mat_<Vec3b>::iterator it = outputimage.begin<Vec3b>();
	Mat_<Vec3b>::iterator itend = outputimage.end<Vec3b>();
	for (; it != itend; ++it)
	{
		(*it)[0] = (*it)[0] / div*div + div / 2;
		(*it)[1] = (*it)[1] / div*div + div / 2;
		(*it)[2] = (*it)[2] / div*div + div / 2;
	}
}
void colorReduce3(Mat& inputimage, Mat & outputimage, int div) {
	outputimage = inputimage.clone();
	int rowNumber = outputimage.rows;
	int colNumber = outputimage.cols;
	for (size_t i = 0; i < rowNumber; i++)
	{
		for (size_t j = 0; j < colNumber; j++)
		{
			outputimage.at<Vec3b>(i, j)[0] =
				outputimage.at<Vec3b>(i, j)[0] / div*div + div / 2;
			outputimage.at<Vec3b>(i, j)[1] =
				outputimage.at<Vec3b>(i, j)[1] / div*div + div / 2;
			outputimage.at<Vec3b>(i, j)[2] =
				outputimage.at<Vec3b>(i, j)[2] / div*div + div / 2;
		}
	}

}

