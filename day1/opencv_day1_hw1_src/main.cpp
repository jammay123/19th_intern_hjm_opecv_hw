#include "opencv_day1_hw1/opencv_day1_hw1.hpp"

int main() {
    ImageProcessor YellowProcessor;
    YellowProcessor.convertToHSV();
    YellowProcessor.filterColor(cv::Scalar(20, 170, 100), cv::Scalar(30, 255, 255));
    //YellowProcessor.blurImage();
    YellowProcessor.displayImage("Yellow line");

    cv::waitKey(0);
    cv::destroyAllWindows();

    std::cout << "필터링 된 이미지" << std::endl;
    return 0;
}
