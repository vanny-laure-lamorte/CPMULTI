#include "DiscreteFourierTransformMenu.ui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void DiscreteFourierTransformMenu::displayDFTMenu(Mat& image) {
    if (image.empty()) {
        cerr << "Error: No valid image loaded!" << endl;
        return;
    }

    DiscreteFourierTransform dftProcessor(image);
    int choice;
    
    do {
        cout << "\n"
        << "       * * * * * * * * * * * * * * * * * * * * * * *\n"
        << "       *                                           *\n"
        << "       *         FOURIER TRANSFORM MENU            *\n"
        << "       *                                           *\n"
        << "       *      (1) Compute DFT                      *\n"
        << "       *      (2) Compute Magnitude Spectrum       *\n"
        << "       *      (3) Show Results                     *\n"
        << "       *      (4) Benchmark Processing Speed       *\n"
        << "       *      (5) Rotate Image using complex image *\n"
        << "       *      (6) Quit                             *\n"
        << "       *                                           *\n"
        << "       * * * * * * * * * * * * * * * * * * * * * * *\n\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int modeChoice, numThreads = 1;
                cout << "\n"
                << "       * * * * * * * * * * * * * * * * * * * * * * *\n"
                << "       *                                           *\n"
                << "       *        SELECT PROCESSING MODE             *\n"
                << "       *                                           *\n"
                << "       *      (1) Single-threaded                  *\n"
                << "       *      (2) Multi-threaded                   *\n"
                << "       *      (3) Multi-threaded with Mutex        *\n"
                << "       *                                           *\n"
                << "       * * * * * * * * * * * * * * * * * * * * * * *\n\n";
           
           cout << "Choose an option: ";
           
                cin >> modeChoice;

                ThreadManager::Mode mode;
                if (modeChoice == 1) mode = ThreadManager::SINGLE_THREAD;
                else if (modeChoice == 2) mode = ThreadManager::MULTI_THREAD;
                else if (modeChoice == 3) mode = ThreadManager::MULTI_THREAD_MUTEX;
                else {
                    cout << "Invalid choice. Defaulting to single-threaded.\n";
                    mode = ThreadManager::SINGLE_THREAD;
                }

                if (mode != ThreadManager::SINGLE_THREAD) {
                    cout << "Enter number of threads: ";
                    cin >> numThreads;
                }

                dftProcessor.computeDFT(mode, numThreads);
                cout << "DFT Computed.\n";
                break;
            }
            case 2:
                dftProcessor.computeMagnitudeSpectrum();
                cout << "Magnitude Spectrum Computed.\n";
                break;
            case 3:
                dftProcessor.showResult();
                break;
            case 4:
                dftProcessor.benchmarkProcessing();
                break;
            case 5:
                double angle;
                cout << "Enter angle to rotate image by: ";
                cin >> angle;
                dftProcessor.rotateImageUsingDFT(angle);
                dftProcessor.showRotatedImage();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (choice != 7);
}