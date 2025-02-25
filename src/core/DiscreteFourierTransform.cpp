// file: DiscreteFourierTransform.cpp
#include "DiscreteFourierTransform.hpp"
#include <iostream>

using namespace cv;
using namespace std;

DiscreteFourierTransform::DiscreteFourierTransform(const Mat& image) {
    if (image.empty()) {
        cerr << "Error: Provided image is empty!" << endl;
        return;
    }
    img = image.clone();
}

DiscreteFourierTransform::~DiscreteFourierTransform() {
    destroyAllWindows();
}

void DiscreteFourierTransform::computeDFT() {
    if (img.empty()) {
        cerr << "Error: No image loaded for DFT computation!" << endl;
        return;
    }

        
    if (img.channels() > 1) {
        cvtColor(img, img, COLOR_BGR2GRAY);
    }
    img.convertTo(img, CV_32F);

    int y = getOptimalDFTSize(img.rows);
    int x = getOptimalDFTSize(img.cols);

    copyMakeBorder(img, padded, 0, y - img.rows, 0, x - img.cols, BORDER_CONSTANT, Scalar::all(0));

    Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};
    merge(planes, 2, complexImage);
    dft(complexImage, complexImage);
}

void DiscreteFourierTransform::computeMagnitudeSpectrum() {
    if (complexImage.empty()) {
        cerr << "Error: Compute DFT first before computing the magnitude spectrum!" << endl;
        return;
    }

    Mat planes[2];
    split(complexImage, planes);

    magnitude(planes[0], planes[1], planes[0]);
    magnitudeSpectrum = planes[0];

    magnitudeSpectrum += Scalar::all(1);
    log(magnitudeSpectrum, magnitudeSpectrum);

    magnitudeSpectrum = magnitudeSpectrum(Rect(0, 0, magnitudeSpectrum.cols & -2, magnitudeSpectrum.rows & -2));
    rearrangeQuadrants();

    normalize(magnitudeSpectrum, magnitudeSpectrum, 0, 1, NORM_MINMAX);
}

void DiscreteFourierTransform::rearrangeQuadrants() {
    int cx = magnitudeSpectrum.cols / 2;
    int cy = magnitudeSpectrum.rows / 2;

    Mat q0(magnitudeSpectrum, Rect(0, 0, cx, cy));
    Mat q1(magnitudeSpectrum, Rect(cx, 0, cx, cy));
    Mat q2(magnitudeSpectrum, Rect(0, cy, cx, cy));
    Mat q3(magnitudeSpectrum, Rect(cx, cy, cx, cy));

    Mat tmp;
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);

    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);
}

Mat DiscreteFourierTransform::rotateImageUsingDFT(double angle) {
    if (complexImage.empty()) {
        cerr << "Error: Compute DFT first before rotating!" << endl;
        return Mat();
    }

    Mat rotatedComplexImage = rotateDFT(complexImage, angle);
    rotatedImage = inverseDFT(rotatedComplexImage);
    return rotatedImage;
}

Mat DiscreteFourierTransform::rotateDFT(const Mat& complexImage, double angle) {
    Point2f center(complexImage.cols / 2.0, complexImage.rows / 2.0);
    Mat rot = getRotationMatrix2D(center, angle, 1.0);
    Rect2f bbox = RotatedRect(Point2f(), complexImage.size(), angle).boundingRect2f();
    rot.at<double>(0, 2) += bbox.width / 2.0 - complexImage.cols / 2.0;
    rot.at<double>(1, 2) += bbox.height / 2.0 - complexImage.rows / 2.0;
    Mat rotatedComplexImage;
    warpAffine(complexImage, rotatedComplexImage, rot, bbox.size());
    return rotatedComplexImage;
}

Mat DiscreteFourierTransform::inverseDFT(const Mat& complexImage) {
    Mat inverseTransform;
    idft(complexImage, inverseTransform, DFT_SCALE | DFT_REAL_OUTPUT);
    return inverseTransform;
}

void DiscreteFourierTransform::showResult() {
        if (img.empty() || magnitudeSpectrum.empty()) {
        cerr << "Error: " 
             << (img.empty() ? "No input image loaded!" : "Compute Magnitude Spectrum first!") 
             << endl;
        return;
    }
    imshow("Input Image", img);
    imshow("Magnitude Spectrum", magnitudeSpectrum);
    waitKey(0);
}

void DiscreteFourierTransform::showRotatedImage() {
    if (rotatedImage.empty()) {
        cerr << "Error: Rotate image first!" << endl;
        return;
    }
    imshow("Rotated Image", rotatedImage);
    waitKey(0);
}

void DiscreteFourierTransform::printMatrices() {
    cout << "Complex Image Matrix: " << endl << complexImage << endl;
}
