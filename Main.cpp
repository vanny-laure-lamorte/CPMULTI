#include "include/TerminalDisplay.h"
#include "include/CannyEdgeDetection.h"
#include "include/GaussianBlurProcessor.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    GaussianBlurProcessor gaussianBlurProcessor;
    gaussianBlurProcessor.userChoice();

    // CannyEdgeDetection cannyEdgeDetection;
    // cannyEdgeDetection.runCannyEdgeDetection();

    // TerminalDisplay terminalDisplay;
    // terminalDisplay.displayWelcomeMessage();
    return 0;
}
