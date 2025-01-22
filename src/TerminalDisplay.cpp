#include "../include/TerminalDisplay.h"
#include "../include/InputValidator.h"
#include <iostream>
using namespace std;
#include <limits>

InputValidator inputValidator;

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
        displayMenu();
}

int TerminalDisplay::displayMenu() {

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
            << "> Please choose an option: ";
        
        cin >> choice;    
    } while (!inputValidator.isValidDigit(choice, 8));
    return choice; 
}