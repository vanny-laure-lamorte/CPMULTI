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
     * @brief Function to apply Gaussian blur with the specified number of threads
     * @anchor applyGaussianBlur
     * @param numThreads Number of threads to use for Gaussian blur
     * @param numAttempts Number of attempts to apply Gaussian blur
     * @return Blurred image
     */
    Mat applyGaussianBlur(int numThreads, int numAttempts);

    // Function to save an image to disk
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
