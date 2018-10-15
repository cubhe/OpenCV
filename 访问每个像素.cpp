#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>
using namespace cv;
using namespace std;

void colorReduce1(Mat& inputimage, Mat & outputimage, int div);
void colorReduce2(Mat& inputimage, Mat & outputimage, int div);
void colorReduce3(Mat& inputimage, Mat & outputimage, int div);

int main() {

	//����ԭʼͼ
	Mat srcimage = imread("aaa.jpg");
	imshow("ԭʼͼ��", srcimage);

	//��ԭʼͼ�Ĳ�����񴴽�Ч��ͼ
	Mat dstimage;
	dstimage.create(srcimage.rows, srcimage.cols, srcimage.type());

	//��¼��ʼʱ��
	double time0 = static_cast<double>(getTickCount());

	//������ɫ��������
	colorReduce3(srcimage, dstimage, 32);

	//��������ʱ�䲢�˳�
	time0 = ((double)getTickCount() - time0) / getTickFrequency();
	cout << "�˷�������ʱ��Ϊ��" << time0 << "��" << endl;

	//��ʾЧ��ͼ
	imshow("Ч��ͼ", dstimage);
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
			//��ʼ����ÿ������
			data[j] = data[j] / div*div + div / 2;

		}
	}
}
void colorReduce2(Mat& inputimage, Mat & outputimage, int div) {
	outputimage = inputimage.clone();
	//��ȡ������
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

