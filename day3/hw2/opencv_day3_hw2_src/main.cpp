#include "red_white_houghlinesp/red_white_houghlinesp.hpp"

int main() {
    ImgProcessor red_white;
    red_white.applyCanny();
    red_white.applyHoughTransform();
    red_white.showImage();

    return 0;
}
