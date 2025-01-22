#include "../include/TerminalDisplay.hpp"

InputValidator inputValidator;
CannyEdgeDetection cannyEdgeDetection;
GaussianBlurProcessor gaussianBlurProcessor;  

void TerminalDisplay::displayWelcomeMessage() {
    cout << "\n"
         << "       * * * * * * * * * * * * * * * * * * * * * * *\n"
         << "       *                                           *\n"
         << "       *                 MUTEXISATION              *\n"
         << "       *                                           *\n"
         << "       *       By Lucas M., Thanh L, Vanny L.      *\n"
         << "       *       B2 Logiciel - 2025                  *\n"
         << "       *                                           *\n"
         << "       * * * * * * * * * * * * * * * * * * * * * * *\n\n"
         << "> Press Enter to continue.";

        cin.get();
        clearScreen();
}

int TerminalDisplay::displayMenu() {
    displayWelcomeMessage();

    int choice;
    do {
        cout << "\n"
            << "       * * * * * * * * * * * * * * * * * * * * * * *\n"
            << "       *                                           *\n"
            << "       *           VISUAL DATA PROCESSING          *\n"
            << "       *                                           *\n"
            << "       *      (1) Canny Edge Detection             *\n"
            << "       *      (2) Denoising                        *\n"
            << "       *      (3) Fourier Transform                *\n"
            << "       *      (4) Gaussian Blur                    *\n"
            << "       *      (5) Median Filter                    *\n"
            << "       *      (6) Resizing                         *\n"
            << "       *      (7) Rotation                         *\n"
            << "       *      (8) Sobel Filter                     *\n"
            << "       *                                           *\n"
            << "       *      (0) Quit                             *\n"
            << "       *                                           *\n"
            << "       * * * * * * * * * * * * * * * * * * * * * * * \n\n"
            << "> Here is the option you have chosen: ";        
        cin >> choice;    

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1;  
        }
    } while (!inputValidator.isValidDigit(choice, 9));
    return choice; 
}

void TerminalDisplay::displayRectangleWithTitle(string text) {
    int textLength = text.length();  
    int rectangleWidth = textLength + 4; 
    cout << endl << string(rectangleWidth, '*') << endl;    
    cout << "* " << text << " *" << endl;
    cout << string(rectangleWidth, '*') << endl;
    cout << endl;
}

void TerminalDisplay::handleMenuChoice(int userMenuChoice) {

    clearScreen(); 

    vector<string> menuListTitle = {
        "CANNY EDGE DETECTION",
        "DENOISING",
        "FOURIER TRANSFORM",
        "GAUSSIAN BLUR",
        "MEDIAN FILTER",
        "RESIZE",
        "ROTATION",
        "SOBEL FILTER"
    };

        if (userMenuChoice >= 1 && userMenuChoice <= menuListTitle.size()) {
        displayRectangleWithTitle(menuListTitle[userMenuChoice - 1]);
        } else if (userMenuChoice!=0){
            cout << "Invalid Menu choice. Try again." << endl;
            return;
        }

        switch (userMenuChoice)
        {
        case 0: 
            cout << endl << endl << "Goodbye. Hope to see you soon ! :)" << endl << endl;
            exit(0);
            break;
        case 1:
            cout << "You chose: Canny Edge Detection" << endl; // Debug
            cannyEdgeDetection.runCannyEdgeDetection();
            break;
        case 2:
            cout << "You chose: Denoising" << endl; // Debug
            break;
        case 3:
            cout << "You chose: Fourier Transform" << endl; // Debug
            break;
        case 4:
            cout << "You chose: Gaussian Blur" << endl; // Debug
            gaussianBlurProcessor.userChoice();
            break;
        case 5:
            cout << "You chose: Median Filter" << endl; // Debug
            break;
        case 6:
            cout << "You chose: Resizing" << endl; // Debug
            break;
        case 7:
            cout << "You chose: Rotation" << endl; // Debug
            break;
        case 8:
            cout << "You chose:  Sobel Filter" << endl;
            break;
        case 9:
            // SECTION FOR TESTING PURPOSES
            break;
        default:
            cout << "Invalid Menu choice. Try again." << endl;
            break;
        }
}

