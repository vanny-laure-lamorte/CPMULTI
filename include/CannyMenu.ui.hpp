#ifndef CANNY_MENU_UI_HPP
#define CANNY_MENU_UI_HPP

#include <opencv2/opencv.hpp>
/**
 * @class CannyMenu
 * @brief Manages the Canny Edge Detection menu
 * @param img Image to process
 */
class CannyMenu
{
    public:
    // CannyMenu(cv::Mat img = cv::Mat())
    // : image(img)
    // {
    // }

    // ~CannyMenu() {}

    void cannyMenu(cv::Mat &img);
    int askForNumThreads();

};

#endif // CANNY_MENU_UI_HPP