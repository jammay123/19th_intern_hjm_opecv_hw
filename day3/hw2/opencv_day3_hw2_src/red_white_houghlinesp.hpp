#ifndef RED_WHITE_HOUGHLINESP_HPP
#define RED_WHITE_HOUGHLINESP_HPP

#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>
#include <vector>

class ImgProcessor {
public:
  ImgProcessor();
  void applyCanny();
  void applyHoughTransform();
  void showImage();

private:
  cv::Mat img;
  cv::Mat edges;
};

#endif // RED_WHITE_HOUGHLINESP_HPP
