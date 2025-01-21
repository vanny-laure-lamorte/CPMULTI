#ifndef GAUSSIANBLURPROCESSOR_HPP
#define GAUSSIANBLURPROCESSOR_HPP

#include <opencv2/opencv.hpp>
#include <thread>
#include <vector>

using namespace cv;
using namespace std;

class GaussianBlurProcessor
{
public:
    // Constructor
    GaussianBlurProcessor();
    ~GaussianBlurProcessor();

    /**
     * @brief Applies Gaussian blur to an image using the specified number of threads.
     *
     * This function divides the image into regions and processes each region
     * in parallel using the specified number of threads. Optionally, it can
     * repeat the operation multiple times for benchmarking purposes.
     *
     * @param numThreads Number of threads to use for processing.
     * @param numAttempts Number of attempts to repeat the operation.
     * @return The resulting blurred image.
     */
    Mat applyGaussianBlur(int numThreads, int numAttempts);

    /** @brief saveImage to save the image to the specified filename
     * @param image
     * @param filename
     */
    void saveImage(const Mat &image, const string &filename);

    // Function to choose user options
    void userChoice();

    // Function to display menu
    void displayMenu();

    // Function to handle choice
    void handleChoice(int choice);

private:
    Mat image;                    // Original image
    Size kernelSize;              // Gaussian kernel size
    std::string imagePath;        // Path to image file
    map<int, double> threadTimes; // Map to store thread execution times
};

#endif // GAUSSIANBLURPROCESSOR_HPP
