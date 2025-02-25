#include "GaussianBlurMenu.ui.hpp"
#include <iostream>

using namespace std;
InputValidator inputValidator2;

void GaussianBlurMenu::displayGaussianMenu(cv::Mat &image)
{
    if (image.empty())
    {
        cerr << "Error: No valid image loaded!" << endl;
        return;
    }

    GaussianBlurProcessor blurProcessor(image);

    int choice;
    do
    {
        cout << "\n"
             << "       * * * * * * * * * * * * * * * * * * * * * * * * * *\n"
             << "       *                                                 *\n"
             << "       *      (1) Apply Gaussian Blur (Single-threaded)  *\n"
             << "       *      (2) Apply Gaussian Blur (Multi-threaded)   *\n"
             << "       *      (3) Graph Execution Time vs. Threads       *\n"
             << "       *      (4) Custom Intensity Blur                  *\n"
             << "       *                                                 *\n"
             << "       *      (5) Exit                                   *\n"
             << "       *                                                 *\n"
             << "       * * * * * * * * * * * * * * * * * * * * * * * * * * \n\n"
             << "> Select an option from the menu: ";
        do
        {
            cin >> choice;
        } while (!inputValidator2.isValidDigit(choice, 5));

        switch (choice)
        {
        case 1:
            blurProcessor.GaussianBlurWithCustomThreads(1);
            break;
        case 2:
        {
            int threads;
            cout << "> Enter number of threads: ";
            cin >> threads;
            blurProcessor.GaussianBlurWithCustomThreads(threads);
            break;
        }
        case 3:
            blurProcessor.graphThreads();
            break;
        case 4:
        {
            int size;
            cout << "> Enter kernel size (odd number, e.g., 3, 5, 7): ";
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
