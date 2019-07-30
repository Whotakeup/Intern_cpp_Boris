#include <opencv2/opencv.hpp>

int main() {
	cv::Mat Img = cv::imread("../Images/src_image.jpg");
	
	if (Img.empty()) {
		std::cout << "Cannot open image";
		return -1;
	}

	cv::Size_<int> size(Img.cols, Img.rows);
	cv::Mat Contour;
	cv::Mat Result;

	cv::Canny(Img, Contour, 200, 250);

	std::vector<std::vector<cv::Point>>simple_contour;
	std::vector<cv::Point> Ox;

	cv::findContours(Contour, simple_contour,cv::RETR_EXTERNAL,1);

	cv::Point_<int> center(Contour.rows / 2, Contour.cols / 2);
	
	for (int i = simple_contour[0][100].x; i <= simple_contour[0][0].x; ++i) {
		Ox.push_back(cv::Point(i,0));
	}
	double hypotenuse_length = sqrt(pow((simple_contour[0][0].x - simple_contour[0][100].x), 2) + pow((simple_contour[0][0].y - simple_contour[0][100].y), 2));
	double angle = asin((Ox.back().x - Ox[0].x) / hypotenuse_length)*180/CV_PI;

	cv::Mat transform = cv::getRotationMatrix2D(center, angle, 1.0);
	cv::warpAffine(Img, Result, transform, size);

	cv::namedWindow("Transform");
	while (true) {

		cv::imshow("Transform", Result);
		int x = cv::waitKey(33);
		if (x == 32) {
			cv::imwrite("../Images/transformation_result.jpg",Result);
		}
		if (x == 27) {
			break; 
		}
		
	}
	cv::destroyWindow("Transform");
	return 0;
}