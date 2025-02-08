#ifndef GAUSSIANBLUR_MENU_UI_HPP
#define GAUSSIANBLUR_MENU_UI_HPP

#include <opencv2/opencv.hpp>
#include "GaussianBlurProcessor.hpp"

class GaussianBlurMenu {
public:
    static void displayGaussianMenu(cv::Mat& image);
};

#endif // GAUSSIANBLURMENU_H
