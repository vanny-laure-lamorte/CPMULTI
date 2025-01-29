#include "../include/TerminalDisplay.hpp"

InputValidator inputValidator;
// CannyEdgeDetection cannyEdgeDetection;
GaussianBlurProcessor gaussianBlurProcessor;  
DiscreteFourierTransform discretfouriertransform("../assets/image.jpg");

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
            << "       *      (9) Quit                             *\n"
            << "       *                                           *\n"
            << "       * * * * * * * * * * * * * * * * * * * * * * * \n\n"
            << "> Select an option from the menu to continue: ";        
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
        case 1:
            cout << "You chose: Canny Edge Detection" << endl; // Debug
            // cannyEdgeDetection.runCannyEdgeDetection();
            break;
        case 2:
            cout << "You chose: Denoising" << endl; // Debug
            break;
        case 3:
            cout << "You chose: Fourier Transform" << endl; // Debug
            discretfouriertransform.LoadImage();
            discretfouriertransform.ComputeDFT();
            discretfouriertransform.computeMagnitudeSpectrum();
            discretfouriertransform.showResult();
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
            cout << "You chose:  Sobel Filter" << endl; // Debug
            break;
        case 9: 
            cout << endl << endl << "Goodbye. Hope to see you soon ! :)" << endl << endl;
            exit(0);
            break;
        default:
            cout << "Invalid Menu choice. Try again." << endl;
            break;
        }

        int submenuOption = submenuChoice();
        handleSubmenuChoice(submenuOption);
}

int TerminalDisplay::submenuChoice() {

    int submenuChoice;
    do {
        cout << "\n"
            << "       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n"
            << "       *                                                         *\n"
            << "       *                   THREAD OPTIONS MENU                   *\n"
            << "       *                                                         *\n"
            << "       *   (1) Custom number of threads                          *\n"
            << "       *   (2) Run multiple attempts with a fixed thread count   *\n"
            << "       *   (3) Run 1000 attempts with varying thread counts      *\n"
            << "       *   (4) SECTION FOR TESTING PURPOSES  // Debug            *\n"
            << "       *                                                         *\n"
            << "       *   (5) Back to Menu                                      *\n"
            << "       *                                                         *\n"
            << "       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n"
            << "> Select an option from the submenu to continue: ";
        cin >> submenuChoice;
    } while (!inputValidator.isValidDigit(submenuChoice, 5));    
    return submenuChoice;
}

int TerminalDisplay::handleSubmenuChoice(int submenuChoice) {

    clearScreen(); 

    do {
        switch (submenuChoice)
        {
        case 1:
            cout << "You chose:  Custom number of threads" << endl; // Debug
            discretfouriertransform.rotateImageUsingDFT(180);
            discretfouriertransform.Showrotatedimage();
            break;
        case 2:
            cout << "You chose: Run multiple attempts with a fixed thread count" << endl; // Debug
            break;
        case 3:
            cout << "You chose: Run 1000 attempts with varying thread counts" << endl; // Debug
            break;
        case 4:
            cout << "You chose: TEST" << endl; // Debug
            break;
        case 5: 
            "Returning to main menu..."; // Debug
            // displayMenu();
            return 0;

        default:
            cout << "Invalid submenu choice. Please Try again." << endl;
            break;
        }
        cin >> submenuChoice;
    } while (!inputValidator.isValidDigit(submenuChoice, 5));
        return submenuChoice;

}

void TerminalDisplay::start() {
    while (true) {
        int userChoice = displayMenu();
        if (userChoice == 9) {
            cout << endl << "Goodbye! See you soon!" << endl;
            break;
        }
        handleMenuChoice(userChoice);
    }
}



