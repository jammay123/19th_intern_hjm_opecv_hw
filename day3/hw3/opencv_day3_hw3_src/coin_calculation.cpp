#include "coin_calculation/coin_calculation.hpp"

ImgProcessor::ImgProcessor() {
    img = cv::imread("/home/jammay/Pictures/Screenshots/opencv_day3_hw3.png", cv::IMREAD_GRAYSCALE);
}

void ImgProcessor::binaryImg() {
  cv::threshold(img, binary_img, 128, 255, cv::THRESH_BINARY);
}

void ImgProcessor::morphologyImg() {
  cv::Mat element_open = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5,5));
  cv::Mat element_close = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(7,7));


  cv::morphologyEx(binary_img, close_img, cv::MORPH_CLOSE, element_close);
  cv::morphologyEx(close_img, open_img, cv::MORPH_OPEN, element_open);
}

void ImgProcessor::labelingImg() {
  int num = cv::connectedComponentsWithStats(open_img, label_img, stats, centroids, 8, CV_32S);
  cv::cvtColor(img, color_img, cv::COLOR_GRAY2BGR);
  for (int i = 1; i < num; i++) {
    int* p = stats.ptr<int>(i);
    double* c = centroids.ptr<double>(i);

    int radius = static_cast<int>(p[2] / 2);

    std::cout << "원" << i << "반지름" << radius << std::endl;

    cv::circle(color_img, cv::Point(static_cast<int>(c[0]), static_cast<int>(c[1])), radius, cv::Scalar(0, 255, 0), 2);

    if (radius <= 30) {
      coin_10++;
    }
    else if (radius <= 40) {
      coin_100++;
    }
    else {
      coin_500++;
    }
  }
}

void ImgProcessor::calCoin () {
  int calValue = (10 * coin_10) + (100 * coin_100) + (500 * coin_500);
  std::string result = "Total : " + std::to_string(calValue) + "Won";
  cv::putText(color_img, result, cv::Point (10, 50), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(0,0,255), 2);
}

void ImgProcessor::showImg() {
  cv::imshow("coin_cal", color_img);
  cv::waitKey(0);
}
