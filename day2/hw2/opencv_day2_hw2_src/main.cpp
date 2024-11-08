#include "rgb_ball_label/rgb_ball_label.hpp"

int main() {
    ImgProcessor red_ball;
    ImgProcessor green_ball;
    ImgProcessor blue_ball;

    red_ball.applyGaussianBlur();
    green_ball.applyGaussianBlur();
    blue_ball.applyGaussianBlur();

    red_ball.convertToHSV();
    green_ball.convertToHSV();
    blue_ball.convertToHSV();

    cv::Scalar lower_red(0, 130, 150);
    cv::Scalar upper_red(35, 255, 255);
    red_ball.filterColor(lower_red, upper_red);
    cv::Scalar lower_green(35, 50, 50);
    cv::Scalar upper_green(85, 255, 255);
    green_ball.filterColor(lower_green, upper_green);
    cv::Scalar lower_blue(100, 100, 50);
    cv::Scalar upper_blue(140, 255, 255);
    blue_ball.filterColor(lower_blue, upper_blue);

    red_ball.applyMorphology();
    green_ball.applyMorphology();
    blue_ball.applyMorphology();

    red_ball.labeling(cv::Scalar(0,0,255));
    green_ball.labeling(cv::Scalar(0,255,0));
    blue_ball.labeling(cv::Scalar(255,0,0));

    red_ball.showImage("red_ball");
    green_ball.showImage("green_ball");
    blue_ball.showImage("blue_ball");

    cv::waitKey(0);

    return 0;
}
