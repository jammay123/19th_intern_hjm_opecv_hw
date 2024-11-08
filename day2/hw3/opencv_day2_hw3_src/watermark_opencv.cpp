#include "watermark_opencv/watermark_opencv.hpp"

void applyWatermark() {
    // 이미지 읽기
    cv::Mat logo = cv::imread("/home/jammay/Documents/카카오톡 받은 파일/opencv_day2_hw3_img2.png");
    cv::Mat background = cv::imread("/home/jammay/Documents/카카오톡 받은 파일/opencv_day2_hw3_img1.png");

    cv::Mat logo2gray;
    cv::cvtColor(logo, logo2gray, cv::COLOR_BGR2GRAY);

    cv::Mat mask;
    cv::threshold(logo2gray, mask, 200, 255, cv::THRESH_BINARY);

    //로고 부분만 남기기 위해 로고 영역을 흰색으로 만듦
    cv::Mat logoMask_reverse;
    cv::bitwise_not(mask, logoMask_reverse);

    //로고와 reverse 로고와 and 연산으로 로고만 추출
    cv::Mat onlyLogo;
    cv::bitwise_and(logo, logo, onlyLogo, logoMask_reverse);


    int height = logo.rows;
    int width = logo.cols;
    int channels = logo.channels();

    //배경이미지에 roi를 적용해 로고와 이미지 크기를 맞춤, 그렇지 않으면 연산이 불가능해짐
    cv::Mat roi = background(cv::Rect(0,0,width, height));

    //여기서 숫자들은 가중치
    //결과 = (roi * 1.0) + (onlylogo) * 0.5) + 0.0
    cv::Mat mix_logo;
    cv::addWeighted(roi, 1.0, onlyLogo, 0.5, 0.0, mix_logo);

    mix_logo.copyTo(background(cv::Rect(0,0,width, height)));

    cv::imshow("mix_logo", background);
    cv::waitKey(0);
}
