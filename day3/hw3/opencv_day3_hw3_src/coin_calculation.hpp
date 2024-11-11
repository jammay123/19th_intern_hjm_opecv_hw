#ifndef COIN_CALCULATION_HPP
#define COIN_CALCULATION_HPP

#include <opencv2/opencv.hpp>
#include <iostream>

class ImgProcessor {
public:
  ImgProcessor();
  void binaryImg();
  void morphologyImg();
  void labelingImg();
  void calCoin();
  void showImg();

private:
  cv::Mat img;
  cv::Mat binary_img;
  cv::Mat open_img;
  cv::Mat close_img;
  cv::Mat label_img;
  cv::Mat color_img;
  cv::Mat stats;
  cv::Mat centroids;
  cv::Mat result;

  int coin_10 = 0;
  int coin_100 = 0;
  int coin_500 = 0;
};

#endif // COIN_CALCULATION_HPP
