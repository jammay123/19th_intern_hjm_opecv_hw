#include "red_white_houghlinesp/red_white_houghlinesp.hpp"

ImgProcessor::ImgProcessor() {
    img = cv::imread("/home/jammay/Documents/카카오톡 받은 파일/opencv_day3_hw2.jpg");
}

void ImgProcessor::applyCanny() {
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    cv::GaussianBlur(gray, gray, cv::Size(5, 5), 1.5);

    cv::Canny(gray, edges, 50, 150);
}

void ImgProcessor::applyHoughTransform() {
    std::vector<cv::Vec4i> lines;
    cv::HoughLinesP(edges, lines, 1, CV_PI / 180, 50, 50, 10);

    for (size_t i = 0; i < lines.size(); ++i) {
        cv::Vec4i l = lines[i];
        cv::line(img, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), cv::Scalar(0, 255, 0), 2, cv::LINE_AA);

        double slope_img = static_cast<double>(l[3] - l[1]) / (l[2] - l[0]);

        double slope_cart = -slope_img;
        std::cout << "직교 좌표계 상 기울기: " << slope_cart << std::endl;
    }
}

void ImgProcessor::showImage() {
    cv::imshow("result", img);
    cv::waitKey(0);
}
