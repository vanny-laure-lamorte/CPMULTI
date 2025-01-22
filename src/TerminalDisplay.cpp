#include "../include/TerminalDisplay.h"

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

int TerminalDisplay::displaySubMenuGaussian(){
    int choice;
    do {
    cout << "\n----- Gaussian Blur Options -----\n";
    cout << "1. Apply Gaussian Blur with a custom number of threads\n";
    cout << "2. Perform multiple attempts with a constant number of threads\n";
    cout << "3. Perform 1000 attempts with varying numbers of threads\n";
    cout << "0. Exit\n";
    cout << "----------------------------------\n";
    cout << "Please enter an option (0-3): ";
    cin >> choice;
    } while(!inputValidator.isValidDigit(choice, 3));
    return choice;
}