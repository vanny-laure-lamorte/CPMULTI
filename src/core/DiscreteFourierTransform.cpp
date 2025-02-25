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
    imgInput = image.clone();
}

DiscreteFourierTransform::~DiscreteFourierTransform() {
    destroyAllWindows();
}

void DiscreteFourierTransform::computeDFT(ThreadManager::Mode mode, int numThreads) {
    img = imgInput.clone();
    if (img.empty()) {
        cerr << "Error: No image loaded for DFT computation!" << endl;
        return;
    }
    if (img.channels() > 1) {
        cvtColor(img, img, COLOR_BGR2GRAY);
    }

    img.convertTo(img, CV_32F, 1.0 / 255.0);

    int optimalRows = getOptimalDFTSize(img.rows);
    int optimalCols = getOptimalDFTSize(img.cols);

    copyMakeBorder(img, padded, 0, optimalRows - img.rows, 0, optimalCols - img.cols, BORDER_CONSTANT, Scalar::all(0));
    padded.convertTo(padded, CV_32F);
    Mat planes[] = {padded.clone(), Mat::zeros(padded.size(), CV_32F)};
    merge(planes, 2, complexImage);
    ThreadManager::processImage(mode, numThreads, complexImage, [](Mat& region, int, int) {
        dft(region, region);
    });
}

void DiscreteFourierTransform::dftProcessing(Mat& image, int yStart, int yEnd) {
    Mat tempRegion = image.rowRange(yStart, yEnd).clone();
    dft(tempRegion, tempRegion);
    tempRegion.copyTo(image.rowRange(yStart, yEnd));
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
    if (complexImage.empty()) {
        cerr << "Error: Complex image is empty! Compute DFT first." << endl;
        return;
    }

    Mat planes[2];
    split(complexImage, planes);
    Mat realPart = planes[0];
    Mat imagPart = planes[1];

    cout << "********** COMPLEX IMAGE MATRIX **********\n";
    for (int i = 0; i < realPart.rows; ++i) {
        for (int j = 0; j < realPart.cols; ++j) {
            double real = realPart.at<float>(i, j);
            double imag = imagPart.at<float>(i, j);

            cout << "(" << real << " + " << imag << "i) ";
        }
        cout << endl;
    }
    cout << "******************************************\n";
}


void DiscreteFourierTransform::benchmarkProcessing() {
    cout << "\n********** BENCHMARKING THREAD PERFORMANCE **********\n";
    cout << "Comparing Single-threaded, Multi-threaded, and Multi-threaded with Mutex...\n\n";

    vector<ThreadManager::Mode> modes = {ThreadManager::SINGLE_THREAD, ThreadManager::MULTI_THREAD, ThreadManager::MULTI_THREAD_MUTEX};
    vector<string> modeNames = {"Single-threaded", "Multi-threaded", "Multi-threaded with Mutex"};

    int numThreads = 4;
    vector<double> executionTimes;

    for (size_t i = 0; i < modes.size(); ++i) {
        cout << "Testing mode: " << modeNames[i] << "...\n";

        auto start = chrono::high_resolution_clock::now();
        computeDFT(modes[i], (modes[i] == ThreadManager::SINGLE_THREAD) ? 1 : numThreads);
        auto end = chrono::high_resolution_clock::now();

        double elapsedTime = chrono::duration<double>(end - start).count();
        executionTimes.push_back(elapsedTime);

        cout << modeNames[i] << " Execution Time: " << elapsedTime << " seconds\n";
    }

    cout << "\n********** PERFORMANCE SUMMARY **********\n";
    cout << "Execution times for different modes:\n";
    for (size_t i = 0; i < modeNames.size(); ++i) {
        cout << modeNames[i] << ": " << executionTimes[i] << " seconds\n";
    }

    cout << "\nBenchmark complete!\n";
}
