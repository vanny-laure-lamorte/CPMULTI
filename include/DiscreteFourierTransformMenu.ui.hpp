#ifndef DISCRETEFOURIERTRANSFORMMENU_H
#define DISCRETEFOURIERTRANSFORMMENU_H

#include <opencv2/opencv.hpp>
#include "DiscreteFourierTransform.hpp"
#include "ThreadManager.hpp"

/**
 * @class DiscreteFourierTransformMenu
 * @brief Class to display and handle the Discrete Fourier Transform menu.
 */
class DiscreteFourierTransformMenu {
public:
    /**
     * @brief Displays the Discrete Fourier Transform menu and handles user input.
     * @param image The image to be processed.
     */
    static void displayDFTMenu(cv::Mat& image);
};

#endif // DISCRETEFOURIERTRANSFORMMENU_H