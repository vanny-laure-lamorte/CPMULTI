#ifndef DISCRETEFOURIERTRANSFORM_HPP
#define DISCRETEFOURIERTRANSFORM_HPP

#include <opencv2/opencv.hpp>
#include "ThreadManager.hpp"

/**
 * @class DiscreteFourierTransform
 * @brief Class to perform Discrete Fourier Transform on an image.
 */
class DiscreteFourierTransform {
public:
    /**
     * @brief Constructor to initialize the class with an image.
     * @param image The input image to be processed.
     */
    explicit DiscreteFourierTransform(const cv::Mat& image);

    /**
     * @brief Destructor of DiscreteFourierTransform class.
     */
    ~DiscreteFourierTransform();

    /**
     * @brief Apply Discrete Fourier Transform to the image.
     * @param mode The threading mode to use (SINGLE_THREAD, MULTI_THREAD, MULTI_THREAD_MUTEX).
     * @param numThreads The number of threads to use.
     */
    void computeDFT(ThreadManager::Mode mode, int numThreads);

    /**
     * @brief Compute the magnitude spectrum of the image.
     */
    void computeMagnitudeSpectrum();

    /**
     * @brief Rotate the image by the given angle using Discrete Fourier Transform.
     * @param angle The angle by which the image is to be rotated.
     * @return The rotated image.
     */
    cv::Mat rotateImageUsingDFT(double angle);

    /**
     * @brief Display the magnitude spectrum of the image and the original image.
     */
    void showResult();

    /**
     * @brief Rotate the complex image by the given angle using Discrete Fourier Transform.
     * @param complexImage The complex image to be rotated.
     * @param angle The angle by which the image is to be rotated.
     * @return The rotated complex image.
     */
    cv::Mat rotateDFT(const cv::Mat& complexImage, double angle);

    /**
     * @brief Compute the inverse Discrete Fourier Transform of the complex image.
     * @param complexImage The complex image to be processed.
     * @return The inverse Discrete Fourier Transform of the complex image.
     */
    cv::Mat inverseDFT(const cv::Mat& complexImage);

    /**
     * @brief Display the rotated image.
     */
    void showRotatedImage();

    /**
     * @brief Print the matrices of the image.
     */
    void printMatrices();

    /**
     * @brief Benchmark the processing speed of different modes.
     */
    void benchmarkProcessing();

private:
    cv::Mat imgInput; ///< The input image.
    cv::Mat img; ///< The image to be processed.
    cv::Mat padded; ///< The padded image.
    cv::Mat complexImage; ///< The complex image after DFT.
    cv::Mat magnitudeSpectrum; ///< The magnitude spectrum of the image.
    cv::Mat rotatedImage; ///< The rotated image.

    /**
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

    /**
     * @brief Perform DFT processing on a portion of the image.
     * @param image The image to be processed.
     * @param yStart The starting row index.
     * @param yEnd The ending row index.
     */
    static void dftProcessing(cv::Mat& image, int yStart, int yEnd);
};

#endif // DISCRETEFOURIERTRANSFORM_HPP
