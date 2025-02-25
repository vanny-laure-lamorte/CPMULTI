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
        cout << "\n********************\n";
        cout << "* FOURIER TRANSFORM MENU *\n";
        cout << "********************\n";
        cout << "1. Compute DFT\n";
        cout << "2. Compute Magnitude Spectrum\n";
        cout << "3. Show Results\n";
        cout << "4. Benchmark Processing Speed (All Modes)\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int modeChoice, numThreads = 1;
                cout << "\nSelect processing mode:\n";
                cout << "1. Single-threaded\n";
                cout << "2. Multi-threaded\n";
                cout << "3. Multi-threaded with Mutex\n";
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
                // dftProcessor.showResult();
                dftProcessor.printMatrices();
                break;
            case 4:
                // dftProcessor.benchmarkProcessing();
                dftProcessor.rotateImageUsingDFT(180);
                break;
            case 5:
                cout << "Exiting Fourier Transform Menu...\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (choice != 5);
}
    