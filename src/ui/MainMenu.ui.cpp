#include "MainMenu.ui.hpp"
#include "CannyMenu.ui.hpp"
#include "DenoisingMenu.ui.hpp"
#include "discreteFourierTransformMenu.ui.hpp"
#include "GaussianBlurMenu.ui.hpp"
#include "ImageManager.io.hpp"

InputValidator inputValidator;
ImageManager imageManager;
CannyEdgeDetection cannyEdgeDetection;
DenoisingMenu denoisingMenu;


void MainMenu::mainMenu(){
    int userChoice;
    displayWelcomeMessage();
    do{
        userChoice = displayMainMenu();
        handleMenuChoice(userChoice);
    } while (userChoice != 4);
    cout << endl
    << "Goodbye! See you soon!" << endl;
}

void MainMenu::displayWelcomeMessage()
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

int MainMenu::displayMainMenu()
{
    int choice;
    do
    {
        cout << "\n"
             << "       * * * * * * * * * * * * * * * * * * * * * * *\n"
             << "       *                                           *\n"
             << "       *            CHOOSE YOUR IMAGE              *\n"
             << "       *                                           *\n"
             << "       *      (1)                                  *\n"
             << "       *      (2)                                  *\n"
             << "       *      (3)                                  *\n"
             << "       *                                           *\n"
             << "       *      (4) Quitter                          *\n"
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
    } while (!inputValidator.isValidDigit(choice, 4));
    return choice;
}

int MainMenu::displayProcessingMenu()
{
    int choice;
    do
    {
        cout << "\n"
             << "       * * * * * * * * * * * * * * * * * * * * * * *\n"
             << "       *                                           *\n"
             << "       *           IMAGE PROCESSING MENU           *\n"
             << "       *                                           *\n"
             << "       *      (1) Canny Edge Detection v           *\n"
             << "       *      (2) Denoising            t           *\n"
             << "       *      (3) Fourier Transform    t           *\n"
             << "       *      (4) Gaussian Blur        l           *\n"
             << "       *      (5) Median Filter        l           *\n"
             << "       *      (6) Resizing            tvl          *\n"
             << "       *      (7) Rotation             t           *\n"
             << "       *      (8) Sobel Filter         v           *\n"
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

void MainMenu::displayRectangleWithTitle(string text)
{
    int textLength = text.length();
    int rectangleWidth = textLength + 4;
    cout << endl
         << string(rectangleWidth, '*') << endl;
    cout << "* " << text << " *" << endl;
    cout << string(rectangleWidth, '*') << endl;
    cout << endl;
}

void MainMenu::handleProcessingChoice(int userChoice)
{

    // clearScreen();

    vector<string> menuListTitle = {
        "CANNY EDGE DETECTION",
        "DENOISING",
        "FOURIER TRANSFORM",
        "GAUSSIAN BLUR",
        "MEDIAN FILTER",
        "RESIZE",
        "ROTATION",
        "SOBEL FILTER"};

    if (userChoice >= 1 && userChoice <= menuListTitle.size())
    {
        displayRectangleWithTitle(menuListTitle[userChoice - 1]);
    }
    else if (userChoice != 0)
    {
        cout << "Invalid Menu choice. Try again." << endl;
        return;
    }

    int submenuOption;

    switch (userChoice)
    {
    case 1:
        cout << "You chose: Canny Edge Detection" << endl; 
        CannyMenu cannyMenu;
        cannyMenu.cannyMenu(image);
    case 2:
        cout << "You chose: Denoising" << endl; 
        denoisingMenu.denoisingMenu(image);
    case 3:
        cout << "You chose: Fourier Transform" << endl; 
        DiscreteFourierTransformMenu::displayDFTMenu(image);
    case 4:
        cout << "You chose: Gaussian Blur" << endl; 
        GaussianBlurMenu::displayGaussianMenu(image);
    case 5:
        cout << "You chose: Median Filter" << endl; 
        break;
    case 6:
        cout << "You chose: Resizing" << endl; 
        break;
    case 7:
        cout << "You chose: Rotation" << endl;
        break;
    case 8:
        cout << "You chose:  Sobel Filter" << endl; 
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

void MainMenu::handleMenuChoice(int userChoice)
{

    // clearScreen();
    string imagePath;

    vector<string> menuListTitle = {
        "CHARGER UNE IMAGE",
        "ACCEDER AU MENU DE TRAITEMENT",
        "SAUVEGARDER L'IMAGE"
    };

    if (userChoice >= 1 && userChoice <= menuListTitle.size())
    {
        displayRectangleWithTitle(menuListTitle[userChoice - 1]);
    }
    else if (userChoice != 0)
    {
        cout << "Invalid Menu choice. Try again." << endl;
        return;
    }

    int submenuOption;

    switch (userChoice)
    {
    case 1:
        cout << "You chose: Charger une image" << endl;
        cout << "Enter the path to the image: ";
        cin >> imagePath;
        image = imageManager.loadImage(imagePath);
        return;
    case 2:
        cout << "You chose: Accéder au menu de traitement" << endl; 
        userChoice = displayProcessingMenu();
        handleProcessingChoice(userChoice);
    case 3:
        cout << "You chose: Sauvegarder l'image" << endl; 
        break;
    case 4:
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

int MainMenu::cannyEdgeDetectorSubmenuChoice()
{

    int cannySubmenuChoice;
    do
    {
        cout << "\n"
             << "       * * * * * * * * * * * * * * * * * * * * * * * * * *\n"
             << "       *                                                 *\n"
             << "       *             THREAD OPTIONS MENU                 *\n"
             << "       *                                                 *\n"
             << "       *   (1) Apply Canny filter with a Trackbar        *\n"
             << "       *   (2) Graph average time vs. number of threads  *\n"
             << "       *                                                 *\n"
             << "       *   (3) Back to Menu                              *\n"
             << "       *                                                 *\n"
             << "       * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n"
             << "> Select an option from the submenu to continue: ";
        cin >> cannySubmenuChoice;
    } while (!inputValidator.isValidDigit(cannySubmenuChoice, 3));
    return cannySubmenuChoice;
}

int MainMenu::handleCannySubmenuChoice(int cannySubmenuChoice)
{
    clearScreen();
    do
    {
        switch (cannySubmenuChoice)
        {
        case 1:
            cannyEdgeDetection.runCannyEdgeDetection();
            break;
        case 2:
            break;
        case 3:
            return 0;
            break;
        default:
            cout << "Invalid submenu choice. Please Try again." << endl;
            break;
        }
        cin >> cannySubmenuChoice;
    } while (!inputValidator.isValidDigit(cannySubmenuChoice, 3));
    return cannySubmenuChoice;
};
