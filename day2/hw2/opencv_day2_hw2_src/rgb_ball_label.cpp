#include "rgb_ball_label/rgb_ball_label.hpp"

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

void ImgProcessor::labeling(const cv::Scalar& labelColor) {

  int labelResult = cv::connectedComponentsWithStats(close_img, label_img, stats, centroids, 8, CV_32S);

  for (int i = 1; i < labelResult; i++) {
        int x = stats.at<int>(i, cv::CC_STAT_LEFT);
        int y = stats.at<int>(i, cv::CC_STAT_TOP);
        int width = stats.at<int>(i, cv::CC_STAT_WIDTH);
        int height = stats.at<int>(i, cv::CC_STAT_HEIGHT);

        cv::rectangle(img, cv::Point(x,y), cv::Point(x + width,y + height), labelColor, 5);
  }
}

void ImgProcessor::showImage(const std::string& imageName) {
  cv::imshow(imageName, img);
}
