#include <opencv2/opencv.hpp>
#include <iostream>
#include "include/GaussianBlurProcessor.hpp"

using namespace cv;
using namespace std;

int main() {
    GaussianBlurProcessor gaussianBlurProcessor;
    gaussianBlurProcessor.userChoice();
    return 0;
}
