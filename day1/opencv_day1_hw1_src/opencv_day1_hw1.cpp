#include "opencv_day1_hw1/opencv_day1_hw1.hpp"

ImageProcessor::ImageProcessor() {
    image = cv::imread("/home/jammay/Documents/카카오톡 받은 파일/opencv_hw1_fix.png");
}

void ImageProcessor::convertToHSV() {
    cv::cvtColor(image, hsvImage, cv::COLOR_BGR2HSV);
}

void ImageProcessor::filterColor(const cv::Scalar& lowerBound, const cv::Scalar& upperBound) {
    cv::inRange(hsvImage, lowerBound, upperBound, filteredImage);
}

/*void ImageProcessor::blurImage(){
  GaussianBlur(filteredImage, bluredImage, cv::Size(5,5),0);
}*/

void ImageProcessor::displayImage(const std::string& windowName) {
    cv::imshow(windowName, filteredImage);    //주석, 변수명 변경 필요
}

