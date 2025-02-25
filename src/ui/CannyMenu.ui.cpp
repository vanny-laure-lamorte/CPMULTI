#include "CannyMenu.ui.hpp"
#include "CannyEdgeDetection.hpp"

#include <iostream>
using namespace std;

CannyEdgeDetection cannyEdgeDetection;


void CannyMenu::cannyMenu(cv::Mat& img) {

    int choiceCannySubmenu;
    int userThreadNumber;
    do {
            cout << "\n"
            << "       * * * * * * * * * * * * * * * * * * * * * * * * * *\n"
            << "       *                                                 *\n"
            << "       *      (1) Apply Canny Edge Detector              *\n"
            << "       *      (2) Apply Canny Edge Detector Cursor       *\n"
            << "       *      (3) Apply Gaussian Blur (Multi-threaded)   *\n"
            << "       *      (4) Graph Execution Time vs. Threads       *\n"
            << "       *                                                 *\n"
            << "       *      (5) Exit                                   *\n"
            << "       *                                                 *\n"
            << "       * * * * * * * * * * * * * * * * * * * * * * * * * * \n\n"
            << "> Select an option from the menu: ";
            cin >> choiceCannySubmenu;
            switch (choiceCannySubmenu) {
                case 1:
                    cannyEdgeDetection.applyCannyEdgeDetector(img);
                    break;
                case 2: 
                    cannyEdgeDetection.runCannyEdgeDetection(img);
                    break;          
                case 3: 
                    userThreadNumber = askForNumThreads();
                    if (userThreadNumber > 1) {
                        cannyEdgeDetection.applyCannyEdgeDetectionWithThreads(img, userThreadNumber);  
                        break;              
                    } else {
                        cout << "\n Invalid number of threads, please try again.\n";
                    }
                    break;
                    
                case 4:
                    cannyEdgeDetection.graphThreads(img);
                    break;
                case 5:
                    break;
                default:
                    cout << "Invalid choice, try again.\n";
            }
    } while(choiceCannySubmenu !=5);
}

int CannyMenu::askForNumThreads() {
    int numThreads;
    cout << "> Enter the number of threads above 1 : ";
    cin >> numThreads;
    
    if (numThreads < 1) {
        cerr << "Error: Number of threads must be at least 1!" << std::endl;
        return -1; 
    }
    return numThreads;
}



