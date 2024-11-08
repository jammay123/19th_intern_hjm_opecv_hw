#ifndef RGB_BALL_LABEL_HPP
#define RGB_BALL_LABEL_HPP

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

class ImgProcessor {
public:
    ImgProcessor();
    void processImage();
    void showImage(const std::string& imageName);
    void applyGaussianBlur();
    void convertToHSV();
    void filterColor(const cv::Scalar& lowerBound, const cv::Scalar& upperBound);
    void applyMorphology();
    void labeling(const cv::Scalar& labelColor);

private:
    cv::Mat img;
    cv::Mat blur_img;
    cv::Mat hsv_img;
    cv::Mat filter_img;
    cv::Mat binary_img;
    cv::Mat open_img;
    cv::Mat close_img;
    cv::Mat label_img;
    cv::Mat stats;
    cv::Mat centroids;
};

#endif // RGB_BALL_LABEL_HPP
