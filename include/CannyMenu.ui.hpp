#ifndef CANNY_MENU_UI_HPP
#define CANNY_MENU_UI_HPP

#include <opencv2/opencv.hpp>
/**
 * @class CannyMenu
 * @brief Manages the Canny Edge Detection menu
 * @param img Image to process
 */
class CannyMenu {
public:
    void cannyMenu(cv::Mat& img);
};

#endif // CANNY_MENU_UI_HPP