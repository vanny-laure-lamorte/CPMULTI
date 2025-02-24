#ifndef CANNYEDGEDETECTION_HPP
#define CANNYEDGEDETECTION_HPP
#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <thread>
#include <mutex>

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
    int applyCannyWithThreads(int numThreads);


    
private:

};

#endif // CANNYEDGEDETECTION_H
