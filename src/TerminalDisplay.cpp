#include "../include/TerminalDisplay.hpp"

InputValidator inputValidator;
// CannyEdgeDetection cannyEdgeDetection;
GaussianBlurProcessor gaussianBlurProcessor;

void TerminalDisplay::displayWelcomeMessage()
{
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

int TerminalDisplay::displayMenu()
{
    displayWelcomeMessage();

    int choice;
    do
    {
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

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1;
        }
    } while (!inputValidator.isValidDigit(choice, 9));
    return choice;
}

void TerminalDisplay::displayRectangleWithTitle(string text)
{
    int textLength = text.length();
    int rectangleWidth = textLength + 4;
    cout << endl
         << string(rectangleWidth, '*') << endl;
    cout << "* " << text << " *" << endl;
    cout << string(rectangleWidth, '*') << endl;
    cout << endl;
}

void TerminalDisplay::handleMenuChoice(int userMenuChoice)
{

    clearScreen();

    vector<string> menuListTitle = {
        "CANNY EDGE DETECTION",
        "DENOISING",
        "FOURIER TRANSFORM",
        "GAUSSIAN BLUR",
        "MEDIAN FILTER",
        "RESIZE",
        "ROTATION",
        "SOBEL FILTER"};

    if (userMenuChoice >= 1 && userMenuChoice <= menuListTitle.size())
    {
        displayRectangleWithTitle(menuListTitle[userMenuChoice - 1]);
    }
    else if (userMenuChoice != 0)
    {
        cout << "Invalid Menu choice. Try again." << endl;
        return;
    }

    int submenuOption;

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
        break;
    case 4:
        cout << "You chose: Gaussian Blur" << endl; // Debug
        submenuOption = gaussianSubmenuChoice();
        handleGaussianSubmenuChoice(submenuOption);
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
        cout << endl
             << endl
             << "Goodbye. Hope to see you soon ! :)" << endl
             << endl;
        exit(0);
        break;
    default:
        cout << "Invalid Menu choice. Try again." << endl;
        break;
    }
}

int TerminalDisplay::gaussianSubmenuChoice()
{
    int submenuChoice;
    do
    {
        cout << "\n"
             << "       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n"
             << "       *                                                         *\n"
             << "       *                   THREAD OPTIONS MENU                   *\n"
             << "       *                                                         *\n"
             << "       *   (1) Gaussian Blur with a custom number of threads     *\n"
             << "       *   (2) Graph average time vs. number of threads          *\n"
             << "       *   (3) Custom Gaussian Blur level                        *\n"
             << "       *   (4) SECTION FOR TESTING PURPOSES  // Debug            *\n"
             << "       *                                                         *\n"
             << "       *   (5) Back to Menu                                      *\n"
             << "       *                                                         *\n"
             << "       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n"
             << "> Select an option from the submenu to continue: ";
        cin >> submenuChoice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            submenuChoice = -1;
        }
    } while (!inputValidator.isValidDigit(submenuChoice, 5));
    return submenuChoice;
}

int TerminalDisplay::gaussianKernelSubmenuChoice()
{
    int kernelOption;
    clearScreen();
    do
    {
    cout << "\n"
         << "       * * * * * * * * * * * * * * * * * *\n"
         << "       *                                 *\n"
         << "       *        BLUR INTENSITY           *\n"
         << "       *                                 *\n"
         << "       *      (1) Low blur               *\n"
         << "       *      (2) Medium blur            *\n"
         << "       *      (3) High blur              *\n"
         << "       *      (4) Very High blur         *\n"
         << "       *                                 *\n"
         << "       *      (5) Quit                   *\n"
         << "       *                                 *\n"
         << "       * * * * * * * * * * * * * * * * * *\n\n"
         << "> Select an option from the menu to continue: ";

    cin >> kernelOption;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        kernelOption = -1;
    } } while (!inputValidator.isValidDigit(kernelOption, 5));
    return kernelOption;
}

int TerminalDisplay::handleGaussianSubmenuChoice(int submenuChoice)
{
    clearScreen();
    do
    {
        switch (submenuChoice)
        {
        case 1:
        {
            int threads;
            cout << "Enter number of threads: ";
            cin >> threads;
            gaussianBlurProcessor.GaussianBlurWithCustomThreads(threads);
            break;
        }
        case 2:
        {
            gaussianBlurProcessor.graphThreads();
            break;
        }
        case 3:
        {
            int kernelOption;
            do{
                kernelOption = gaussianKernelSubmenuChoice();
                Size kernelSize;
                switch (kernelOption)
                {
                case 1:
                    kernelSize = Size(5, 5);
                    break;
                case 2:
                    kernelSize = Size(15, 15);
                    break;
                case 3:
                    kernelSize = Size(31, 31);
                    break;
                case 4:
                    kernelSize = Size(61, 61);
                    break;
                case 5:
                    return 0;
                default:
                    cout << "Invalid option\n";
                    return 0;
                }
                gaussianBlurProcessor.customGaussianBlurIntensity(kernelSize);
            }while(kernelOption != 5);
            break;
        }
        case 4:
        {
            cout << "You chose: TEST" << endl; // Debug
            break;
        }
        case 5:
        {
            "Returning to main menu..."; // Debug
            gaussianSubmenuChoice();
            return 0;
        }
        default:
            cout << "Invalid submenu choice. Please Try again." << endl;
            break;
        }
        //cin >> submenuChoice;
    } while (!inputValidator.isValidDigit(submenuChoice, 5));
    return submenuChoice;
}

void TerminalDisplay::start()
{
    while (true)
    {
        int userChoice = displayMenu();
        if (userChoice == 9)
        {
            cout << endl
                 << "Goodbye! See you soon!" << endl;
            break;
        }
        handleMenuChoice(userChoice);
    }
}
