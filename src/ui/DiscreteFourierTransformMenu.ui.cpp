#include "DiscreteFourierTransformMenu.ui.hpp"
#include <iostream>

using namespace std;

void DiscreteFourierTransformMenu::displayDFTMenu(cv::Mat& image) {
if (image.empty()) {
        cerr << "Error: No image loaded!" << endl;
        return;
    }

    DiscreteFourierTransform dftProcessor(image);

    int choice;
    do {
        cout << "\n=== Discrete Fourier Transform Menu ===\n";
        cout << "1. Compute DFT\n";
        cout << "2. Compute Magnitude Spectrum\n";
        cout << "3. Rotate Image Using DFT\n";
        cout << "4. Show Results\n";
        cout << "5. Print Matrices\n";
        cout << "6. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                dftProcessor.computeDFT();
                cout << "DFT Computed.\n";
                break;
            case 2:
                dftProcessor.computeMagnitudeSpectrum();
                cout << "Magnitude Spectrum Computed.\n";
                break;
            case 3: {
                double angle;
                cout << "Enter rotation angle: ";
                cin >> angle;
                dftProcessor.rotateImageUsingDFT(angle);
                cout << "Image Rotated.\n";
                break;
            }
            case 4:
                dftProcessor.showResult();
                break;
            case 5:
                dftProcessor.printMatrices();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (choice != 6);
}