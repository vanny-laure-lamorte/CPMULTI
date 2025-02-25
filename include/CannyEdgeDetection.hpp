#ifndef CANNYEDGEDETECTION_HPP
#define CANNYEDGEDETECTION_HPP
#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include "matplotlibcpp.h"

using namespace std;
using namespace cv;

class CannyEdgeDetection{
public:

    Mat src, src_gray;
    Mat dst, detected_edges;        
    int lowThreshold = 0;
    const int max_lowThreshold = 100;
    const int ratio = 3;
    const int kernel_size = 3;
    const char* window_name = "Edge Map";

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

    /**
     * Function 
     */
    void CannyThreshold(int, void*);

    /**
     * Function to allows dynamically applying the Canny edge detector to an image using a trackbar to adjust detection thresholds.
     */
    void runCannyEdgeDetection(cv::Mat& image);
    /**
     * Function to allows dynamically applying the Canny edge detector to an image using a trackbar to adjust detection thresholds.
     */

    // Function to apply Canny edge detection with a fixed number of threads
    void applyCannyEdgeDetector(cv::Mat &img);

    void applyCannyEdgeDetectionWithThreads(cv::Mat &img, int numThreads);

    void graphThreads(cv::Mat &img);

    double timeApplyCannyEdge(cv::Mat &img, int numThreads);
    
private:

};

#endif // CANNYEDGEDETECTION_H
