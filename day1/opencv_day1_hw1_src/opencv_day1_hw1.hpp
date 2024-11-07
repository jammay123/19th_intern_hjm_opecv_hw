#ifndef OPENCV_DAY1_HW1_HPP
#define OPENCV_DAY1_HW1_HPP

#include <opencv2/opencv.hpp>
#include <iostream>

class ImageProcessor {
public:
    ImageProcessor();
    void convertToHSV();
    void filterColor(const cv::Scalar& lowerBound, const cv::Scalar& upperBound);
    void displayImage(const std::string& windowName);
    void blurImage();

private:
    cv::Mat image;
    cv::Mat hsvImage;
    cv::Mat filteredImage;
    cv::Mat bluredImage;
};

#endif // OPENCV_DAY1_HW1_HPP
