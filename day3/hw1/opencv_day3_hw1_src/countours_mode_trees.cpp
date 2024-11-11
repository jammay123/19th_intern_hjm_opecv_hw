#include "countours_mode_trees/countours_mode_trees.hpp"
#include <iostream>

ContoursProcessor::ContoursProcessor() {
    img = cv::imread("/home/jammay/Documents/카카오톡 받은 파일/opencv_day3_hw1.png", cv::IMREAD_GRAYSCALE);

    cv::cvtColor(img, img_external, cv::COLOR_GRAY2BGR);
    cv::cvtColor(img, img_list, cv::COLOR_GRAY2BGR);
    cv::cvtColor(img, img_ccomp, cv::COLOR_GRAY2BGR);
    cv::cvtColor(img, img_tree, cv::COLOR_GRAY2BGR);
}

void ContoursProcessor::findExternalContours() {
    cv::findContours(img, cntr_external, cntr_external_hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
}

void ContoursProcessor::findListContours() {
    cv::findContours(img, cntr_list, cntr_list_hierarchy, cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE);
}

void ContoursProcessor::findCCompContours() {
    cv::findContours(img, cntr_ccomp, cntr_ccomp_hierarchy, cv::RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);
}

void ContoursProcessor::findTreeContours() {
    cv::findContours(img, cntr_tree, cntr_tree_hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
}

void ContoursProcessor::drawContours() {
    cv::drawContours(img_external, cntr_external, -1, cv::Scalar(0, 0, 255), 2);
    cv::drawContours(img_list, cntr_list, -1, cv::Scalar(0, 255, 0), 2);
    cv::drawContours(img_ccomp, cntr_ccomp, -1, cv::Scalar(255, 0, 0), 2);
    cv::drawContours(img_tree, cntr_tree, -1, cv::Scalar(255, 0, 255), 2);
}

//계층 정보 확인용 출력
void ContoursProcessor::printHierarchy() {
  std::cout << "\nEXTERNAL 계층 정보 : " << std::endl;
  for (int i = 0; i < cntr_external.size(); i++)
  {
    cv::Vec4i& info = cntr_external_hierarchy[i];
    std::cout << "컨투어 번호" << i << ": 다음 = " << info[0] << ", 이전 = " << info[1] << ", 자식 = " << info[2] << ", 부모 = " << info[3] << std::endl;
  }

  std::cout << "\nLIST 계층 정보 : " << std::endl;
  for (int i = 0; i < cntr_list.size(); i++)
  {
    cv::Vec4i& info = cntr_list_hierarchy[i];
    std::cout << "컨투어 번호" << i << ": 다음 = " << info[0] << ", 이전 = " << info[1] << ", 자식 = " << info[2] << ", 부모 = " << info[3] << std::endl;
  }


  std::cout << "\nCCOMP 계층 정보 : " << std::endl;
  for (int i = 0; i < cntr_ccomp.size(); i++)
  {
    cv::Vec4i& info = cntr_ccomp_hierarchy[i];
    std::cout << "컨투어 번호" << i << ": 다음 = " << info[0] << ", 이전 = " << info[1] << ", 자식 = " << info[2] << ", 부모 = " << info[3] << std::endl;
  }

  std::cout << "\nTREE 계층 정보 :" << std::endl;
  for (int i = 0; i < cntr_tree_hierarchy.size(); i++)
  {
    cv::Vec4i& info = cntr_tree_hierarchy[i];
    std::cout << "컨투어 번호" << i << ": 다음 = " << info[0] << ", 이전 = " << info[1] << ", 자식 = " << info[2] << ", 부모 = " << info[3] << std::endl;
  }
}

void ContoursProcessor::showImages() {
    cv::imshow("RETR_EXTERNAL", img_external);
    cv::imshow("RETR_LIST", img_list);
    cv::imshow("RETR_CCOMP", img_ccomp);
    cv::imshow("RETR_TREE", img_tree);
    cv::waitKey(0);
}
