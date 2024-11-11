#include "coin_calculation/coin_calculation.hpp"

int main() {
    ImgProcessor coin_cal;
    coin_cal.binaryImg();
    coin_cal.morphologyImg();
    coin_cal.labelingImg();
    coin_cal.calCoin();
    coin_cal.showImg();
    return 0;
}
