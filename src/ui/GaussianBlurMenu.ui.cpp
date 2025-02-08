#include "GaussianBlurMenu.ui.hpp"
#include <iostream>

using namespace std;

void GaussianBlurMenu::displayGaussianMenu(cv::Mat& image) {
    if (image.empty()) {
        cerr << "Error: No valid image loaded!" << endl;
        return;
    }

    GaussianBlurProcessor blurProcessor(image);

    int choice;
    do {
        cout << "\n************* GAUSSIAN BLUR MENU *************\n";
        cout << "1. Apply Gaussian Blur (Single-threaded)\n";
        cout << "2. Apply Gaussian Blur (Multi-threaded)\n";
        cout << "3. Graph Execution Time vs. Threads\n";
        cout << "4. Custom Intensity Blur\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                blurProcessor.GaussianBlurWithCustomThreads(1);
                break;
            case 2: {
                int threads;
                cout << "Enter number of threads: ";
                cin >> threads;
                blurProcessor.GaussianBlurWithCustomThreads(threads);
                break;
            }
            case 3:
                blurProcessor.graphThreads();
                break;
            case 4: {
                int size;
                cout << "Enter kernel size (odd number, e.g., 3, 5, 7): ";
                cin >> size;
                blurProcessor.customGaussianBlurIntensity(Size(size, size));
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (choice != 5);
}
