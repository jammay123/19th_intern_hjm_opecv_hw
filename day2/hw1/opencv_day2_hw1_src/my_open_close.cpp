#include "my_open_close/my_open_close.hpp"

ImgProcessor::ImgProcessor() {
  img = cv::imread("/home/jammay/Documents/카카오톡 받은 파일/opencv_hw1.jpg");
}

void ImgProcessor::applyGaussianBlur() {
  cv::GaussianBlur(img, blur_img, cv::Size(5, 5), 0);
}

void ImgProcessor::convertToHSV() {
  cv::cvtColor(blur_img, hsv_img, cv::COLOR_BGR2HSV);
}

void ImgProcessor::filterColor(const cv::Scalar& lowerBound, const cv::Scalar& upperBound) {
  cv::inRange(hsv_img, lowerBound, upperBound, filter_img);
}

void ImgProcessor::applyMorphology() {
  cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));
  cv::morphologyEx(filter_img, open_img, cv::MORPH_OPEN, element);
  cv::morphologyEx(open_img, close_img, cv::MORPH_CLOSE, element);
}

void ImgProcessor::myMorphology() {
  cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));

  cv::Mat opened_img;
  cv::erode(filter_img, open_img, element);
  cv::dilate(open_img, open_img, element);

  cv::Mat closed_img;
  cv::dilate(open_img, close_img, element);
  cv::erode(close_img, close_img, element);
}

void ImgProcessor::showImage(const std::string& imageName) {
  cv::imshow(imageName, close_img);
}
