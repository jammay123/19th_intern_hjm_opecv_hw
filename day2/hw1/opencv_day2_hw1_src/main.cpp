#include "my_open_close/my_open_close.hpp"

int main() {
    ImgProcessor red_ball;
    ImgProcessor green_ball;
    ImgProcessor blue_ball;
    ImgProcessor my_red_ball;
    ImgProcessor my_green_ball;
    ImgProcessor my_blue_ball;

    red_ball.applyGaussianBlur();
    green_ball.applyGaussianBlur();
    blue_ball.applyGaussianBlur();
    my_red_ball.applyGaussianBlur();
    my_green_ball.applyGaussianBlur();
    my_blue_ball.applyGaussianBlur();

    red_ball.convertToHSV();
    green_ball.convertToHSV();
    blue_ball.convertToHSV();
    my_red_ball.convertToHSV();
    my_green_ball.convertToHSV();
    my_blue_ball.convertToHSV();

    cv::Scalar lower_red(0, 130, 150);
    cv::Scalar upper_red(35, 255, 255);
    red_ball.filterColor(lower_red, upper_red);
    cv::Scalar lower_green(35, 50, 50);
    cv::Scalar upper_green(85, 255, 255);
    green_ball.filterColor(lower_green, upper_green);
    cv::Scalar lower_blue(100, 100, 50);
    cv::Scalar upper_blue(140, 255, 255);
    blue_ball.filterColor(lower_blue, upper_blue);

    my_red_ball.filterColor(lower_red, upper_red);
    my_green_ball.filterColor(lower_green, upper_green);
    my_blue_ball.filterColor(lower_blue, upper_blue);

    red_ball.applyMorphology();
    green_ball.applyMorphology();
    blue_ball.applyMorphology();

    my_red_ball.myMorphology();
    my_green_ball.myMorphology();
    my_blue_ball.myMorphology();

    red_ball.showImage("red_ball");
    green_ball.showImage("green_ball");
    blue_ball.showImage("blue_ball");
    my_red_ball.showImage("my_red_ball");
    my_green_ball.showImage("my_green_ball");
    my_blue_ball.showImage("my_blue_ball");

    cv::waitKey(0);

    return 0;
}
