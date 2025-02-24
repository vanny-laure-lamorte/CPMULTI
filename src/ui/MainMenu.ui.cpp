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

void MainMenu::mainMenu()
{
    displayWelcomeMessage();

    int userMenuChoice;
    do
    {
        userMenuChoice = displaySubmenuImageSelection();
        if (userMenuChoice != 10)
        {
            int userFilterMenuChoice = displayFilterMenu();
            handleFilterChoice(userFilterMenuChoice);
        }
    } while (userMenuChoice != 10);
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

int MainMenu::displaySubmenuImageSelection()
{
    int choiceImageUser;
    do
    {
        cout << "\n"
             << "       * * * * * * * * * * * * * * * * * * * * * * *\n"
             << "       *                                           *\n"
             << "       *            CHOOSE YOUR IMAGE              *\n"
             << "       *                                           *\n"
             << "       *      (1) Dragon                           *\n"
             << "       *      (2) Horse                            *\n"
             << "       *      (3) Monkey                           *\n"
             << "       *      (4) Pig                              *\n"
             << "       *      (5) Rabbit                           *\n"
             << "       *      (6) Rooster                          *\n"
             << "       *      (7) Sheep                            *\n"
             << "       *      (8) Snake                            *\n"
             << "       *      (9) Tiger                            *\n"
             << "       *                                           *\n"
             << "       * * * * * * * * * * * * * * * * * * * * * * * \n\n"
             << "> Select an image: ";
        cin >> choiceImageUser;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choiceImageUser = -1;
        }
    } while (!inputValidator.isValidDigit(choiceImageUser, 9));

    image = imageManager.loadImage(choiceImageUser);
    return choiceImageUser;
}

int MainMenu::displayFilterMenu()
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
             << "       *      (9) Previous                         *\n"
             << "       *      (10) Quit                            *\n"
             << "       *                                           *\n"
             << "       * * * * * * * * * * * * * * * * * * * * * * * \n\n"
             << "> Select an option from the menu: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1;
        }
    } while (!inputValidator.isValidDigit(choice, 10));
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

void MainMenu::handleFilterChoice(int userFilterChoice)
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

    if (userFilterChoice >= 1 && userFilterChoice <= menuListTitle.size())
    {
        displayRectangleWithTitle(menuListTitle[userFilterChoice - 1]);
    }
    else if (userFilterChoice != 0)
    {
        cout << "Invalid Menu choice. Try again." << endl;
        return;
    }

    switch (userFilterChoice)
    {
    case 1:
        CannyMenu cannyMenu;
        cannyMenu.cannyMenu(image);
    case 2:
        denoisingMenu.denoisingMenu(image);
    case 3:
        DiscreteFourierTransformMenu::displayDFTMenu(image);
    case 4:
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
};

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
