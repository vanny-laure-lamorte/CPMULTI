#ifndef DENOISINGMENU_HPP
#define DENOISINGMENU_HPP
#include <opencv2/opencv.hpp>
#include <iostream>


/**
 * @class DenoisingMenu
 * @brief Manages the denoising menu
 * @param img Image to process
 */
class DenoisingMenu
{
    public:
        /**
         * @brief Function to display the denoising menu
         */
        void denoisingMenu(cv::Mat& img);
};

#endif  // DENOISINGMENU_HPP