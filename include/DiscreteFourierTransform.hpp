#ifndef DISCRETEFOURIERTRANSFORM_HPP
#define DISCRETEFOURIERTRANSFORM_HPP

#include <opencv2/opencv.hpp>
/**
* @class DiscreteFourierTransform
* @brief Class to perform Discrete Fourier Transform on an image.
* @return The resulting image after applying Discrete Fourier Transform.
*/
class DiscreteFourierTransform {
public:
    /**
     * @class DiscreteFourierTransform
     * @brief Default constructor.
     * @brief Load the image from the given filename.
     * @param filename The name of the image file.
     * @return True if the image is loaded successfully, false otherwise.
     */
    explicit DiscreteFourierTransform(const cv::Mat& image);
    /**
     * @class DiscreteFourierTransform
     * @brief Destructor of DiscreteFourierTransform class.
     */
    ~DiscreteFourierTransform();
    /**
     * @class DiscreteFourierTransform
     * @brief Apply Discrete Fourier Transform to the image.
    */
    void computeDFT();
    /**
     * @class DiscreteFourierTransform
     * @brief Compute the magnitude spectrum of the image.
     */
    void computeMagnitudeSpectrum();
    /**
     * @class DiscreteFourierTransform
     * @brief Rotate the image by the given angle using Discrete Fourier Transform.
     * @param angle The angle by which the image is to be rotated.
     * @return The rotated image.
     */
    cv::Mat rotateImageUsingDFT(double angle);
    void showImgResult();
    /**
     * @class DiscreteFourierTransform
     * @brief Display the magnitude spectrum of the image and the image.
     */
    void showResult();
        /**
     * @class DiscreteFourierTransform
     * @brief Display the magnitude spectrum of the image.
     * @param complexImage The complex image.
     * @param angle The angle by which the image is to be rotated.
     * @return rotatedComplexImage The rotated complex image.
     */
    cv::Mat rotateDFT(const cv::Mat& complexImage, double angle);
        /**
     * @class DiscreteFourierTransform
     * @brief Compute the inverse Discrete Fourier Transform of the complexImage.
     * @param complexImage The complex image to be processed.
     * @return The inverse Discrete Fourier Transform of the complexImage.
     */
    cv::Mat inverseDFT(const cv::Mat& complexImage);
    /**
     * @class DiscreteFourierTransform
     * @brief Display the rotated image.
     */
    void showRotatedImage();
    /**
     * @class DiscreteFourierTransform
     * @brief Print the matrices of the image.
     */
    void printMatrices();

private:
    cv::Mat img, padded, complexImage, magnitudeSpectrum, rotatedImage;
    /**
     * @class DiscreteFourierTransform
     * @brief Rearrange the quadrants of the image.
     * 
     * The quadrants are rearranged so that the origin is at the center of the image.
     * 
     * The quadrants are rearranged in the following manner:
     * 
     * 2 1
     * 
     * 3 0
     * 
     * for a 4 quadrant image.
     * 
     * This gives the image a more intuitive appearance,
     * since the origin is at the center of the image.
     */
    void rearrangeQuadrants();
};

#endif // DISCRETEFOURIERTRANSFORM_HPP
