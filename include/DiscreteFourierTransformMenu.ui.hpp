#ifndef DISCRETEFOURIERTRANSFORM_MENU_UI_HPP
#define DISCRETEFOURIERTRANSFORM_MENU_UI_HPP

#include <opencv2/opencv.hpp>
#include "DiscreteFourierTransform.hpp"
/**
 * @class DiscreteFourierTransformMenu
 * @brief The DiscreteFourierTransformMenu class
 * This class is used to display the menu for the Discrete Fourier Transform
 * operations.
 */
class DiscreteFourierTransformMenu {
public:
    /**
     * @class DiscreteFourierTransformMenu
     * @brief displayDFTMenu
     * This function displays the menu for the Discrete Fourier Transform
     * operations.
     * @param image The image on which the operations are to be performed.
     */
    static void displayDFTMenu(cv::Mat& image);
};

#endif // DISCRETEFOURIERTRANSFORMMENU_H
