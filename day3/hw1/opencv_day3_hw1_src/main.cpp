#include "countours_mode_trees/countours_mode_trees.hpp"

int main() {
    // 이미지 경로 설정
    ContoursProcessor processor;

    // 컨투어 찾기 및 그리기
    processor.findExternalContours();
    processor.findListContours();
    processor.findCCompContours();
    processor.findTreeContours();
    processor.drawContours();
    processor.printHierarchy();

    // 결과 이미지 출력
    processor.showImages();

    return 0;
}
