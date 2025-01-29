// file: DiscreteFourierTransform.cpp
#include "../include/DiscreteFourierTransform.hpp"

DiscreteFourierTransform::DiscreteFourierTransform(const string& filename) : filename(filename) {}
DiscreteFourierTransform::~DiscreteFourierTransform()
{
    destroyAllWindows();
}

bool DiscreteFourierTransform::LoadImage() {
    img = imread(filename, IMREAD_GRAYSCALE);
    if(img.empty())
    {
        cerr << "Could not open or find the image!\n" << endl;
        return false;
    }
    return true;
}

void DiscreteFourierTransform::ComputeDFT() {
    int y = getOptimalDFTSize(img.rows);
    int x = getOptimalDFTSize(img.cols);

    copyMakeBorder(img, padded, 0, y - img.rows, 0, x - img.cols, BORDER_CONSTANT, Scalar::all(0));

    Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};
    Mat complexI;
    merge(planes, 2, complexI);
    dft(complexI, complexI);
}
void DiscreteFourierTransform::computeMagnitudeSpectrum() {

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

void  DiscreteFourierTransform::rearrangeQuadrants() {
    int cx = magnitudeSpectrum.cols/2;
    int cy = magnitudeSpectrum.rows/2;

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

void DiscreteFourierTransform::showResult() {
    imshow("Input Image", img);
    imshow("Magnitude Spectrum", magnitudeSpectrum);
    waitKey();
}