#ifndef DISCRETEFOURIERTRANSFORM_HPP
#define DISCRETEFOURIERTRANSFORM_HPP

#include <opencv2/opencv.hpp>

class DiscreteFourierTransform {
public:
    explicit DiscreteFourierTransform(const cv::Mat& image);
    ~DiscreteFourierTransform();

    void computeDFT();
    void computeMagnitudeSpectrum();
    cv::Mat rotateImageUsingDFT(double angle);
    void showImgResult();
    void showResult();
    void showRotatedImage();
    void printMatrices();

private:
    cv::Mat img, padded, complexImage, magnitudeSpectrum, rotatedImage;

    void rearrangeQuadrants();
    cv::Mat rotateDFT(const cv::Mat& complexImage, double angle);
    cv::Mat inverseDFT(const cv::Mat& complexImage);
};

#endif // DISCRETEFOURIERTRANSFORM_HPP
