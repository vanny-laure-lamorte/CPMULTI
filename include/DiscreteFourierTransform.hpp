// file : DiscreteFourierTransform.hpp
#ifndef DISCRETEFOURIERTRANSFORM_HPP
#define DISCRETEFOURIERTRANSFORM_HPP

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>

using namespace cv;
using namespace std;
/*
* @brief Class to perform Discrete Fourier Transform on an image.
* @return The resulting image after applying Discrete Fourier Transform.
*/
class DiscreteFourierTransform
{
    public:
    /*
    * @brief Load the image from the given filename.
    * @param filename The name of the image file.
    * @return True if the image is loaded successfully, false otherwise.
    */
    DiscreteFourierTransform(const string& filename);
    /*
    * @brief Destructor of DiscreteFourierTransform class.
    */
    ~DiscreteFourierTransform();
    /*
    * @brief Load the image from the given filename.
    * @return True if the image is loaded successfully, false otherwise.
    */
    bool LoadImage();
    /*
    * @brief Apply Discrete Fourier Transform to the image.
    */
    void ComputeDFT();
    /*
    * @brief Compute the magnitude spectrum of the image.
    */
    void computeMagnitudeSpectrum();
    /*
    * @brief Display the magnitude spectrum of the image and the orignal image.
    */
    void showResult();
    void printMatrices();

    Mat rotateImageUsingDFT(double angle);
    Mat rotateDFT(const Mat& complexImage, double angle);
    Mat inverseDFT(const Mat& complexImage);
    void Showrotatedimage();
  

    protected:
    private:
    string filename;
    Mat img, padded, complexImage, magnitudeSpectrum, rotatedImage;
/*
    * @brief Rearrange the quadrants of the image.
    * 
    * The quadrants are rearranged so that the origin is at the center of the image.
    * 
    * The quadrants are rearranged in the following manner:
    * 
    * 2 1
    * 
    * 3 0
    * 
    * for a 4 quadrant image.
    * 
    * This gives the image a more intuitive appearance,
    * since the origin is at the center of the image.
    */
    void rearrangeQuadrants();
};
#endif // DISCRETEFOURIERTRANSFORM_HPP