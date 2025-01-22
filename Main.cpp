#include "include/TerminalDisplay.h"
#include "include/CannyEdgeDetection.h"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    CannyEdgeDetection cannyEdgeDetection;

    cannyEdgeDetection.runCannyEdgeDetection();

    // TerminalDisplay terminalDisplay;
    // terminalDisplay.displayWelcomeMessage();
};
