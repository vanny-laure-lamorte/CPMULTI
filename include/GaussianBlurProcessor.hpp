#ifndef GAUSSIAN_BLUR_PROCESSOR_HPP
#define GAUSSIAN_BLUR_PROCESSOR_HPP

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <thread>
#include <vector>
#include "matplotlibcpp.h"
#include "TerminalDisplay.hpp"
using namespace cv;
using namespace std;

/**
 * @class GaussianBlurProcessor
 * @brief Manages image processing with Gaussian blur using multithreading
 * 
 * This class provides functionality for applying Gaussian blur to images,
 * supporting single and multi-threaded processing, performance benchmarking,
 * and visualization of processing results.
 */
class GaussianBlurProcessor {
private:
    /// Input image to be processed
    Mat image;

    /**
     * @brief Plots performance graph using matplotlib
     * 
     * @param xValues X-axis values for graph
     * @param yValues Y-axis values for graph
     * @param title Graph title
     * @param xLabel X-axis label
     * @param yLabel Y-axis label
     */
    void plotGraph(const vector<int>& xValues, 
                   const vector<double>& yValues, 
                   const string& title, 
                   const string& xLabel, 
                   const string& yLabel);

public:
    /**
     * @brief Construct a new Gaussian Blur Processor
     * Loads default image from assets
     */
    GaussianBlurProcessor();

    /**
     * @brief Destructor to clean up windows
     */
    ~GaussianBlurProcessor();

    /**
     * @brief Applies Gaussian blur using specified number of threads
     * 
     * @param numThreads Number of threads for parallel processing
     * @return Mat Processed blurred image
     */
    pair<Mat, double> applyGaussianBlur(int numThreads);

    /**
     * @brief Graphs performance across different thread counts
     */
    void graphThreads();

    /**
     * @brief Displays interactive menu for blur processing
     */
    void userChoice();

    /**
     * @brief Displays processing options menu
     */
    void displayMenu();

    /**
     * @brief Handles user menu selection
     * 
     * @param choice Selected menu option
     */
    void handleChoice(int choice);
};

#endif // GAUSSIAN_BLUR_PROCESSOR_HPP