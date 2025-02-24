#include <opencv2/photo.hpp>
#include <iostream>

#include "denoisingMenu.ui.hpp"

using namespace std;
using namespace cv;

void DenoisingMenu::denoisingMenu(Mat& img)
{
    if (img.empty()) {
        cerr << "Error: No image loaded!" << endl;
        return;
    }

    int h;
    cout << "Enter the denoising parameter (10-50 recommended): ";
    cin >> h;

    if (h < 1 || h > 100) {
        cerr << "Invalid value, using default value (10)." << endl;
        h = 10;
    }

    Mat denoisedImage;
    fastNlMeansDenoisingColored(img, denoisedImage, h, h, 7, 21);

    img = denoisedImage;

    imshow("Denoised Image", img);
    waitKey(0);
}
