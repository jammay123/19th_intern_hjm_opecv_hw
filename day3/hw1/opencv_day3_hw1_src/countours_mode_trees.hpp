#ifndef CONTOURS_MODE_TREES_HPP
#define CONTOURS_MODE_TREES_HPP

#include <opencv2/opencv.hpp>
#include <vector>
#include <string>

class ContoursProcessor {
public:
    ContoursProcessor();
    void findExternalContours();
    void findListContours();
    void findCCompContours();
    void findTreeContours();
    void drawContours();
    void printHierarchy();
    void showImages();

private:
    cv::Mat img;
    std::vector<std::vector<cv::Point>> cntr_external, cntr_list, cntr_ccomp, cntr_tree;
    std::vector<cv::Vec4i> cntr_external_hierarchy, cntr_list_hierarchy, cntr_ccomp_hierarchy, cntr_tree_hierarchy;
    cv::Mat img_external, img_list, img_ccomp, img_tree;
};

#endif // CONTOURS_MODE_TREES_HPP
