#include "MainMenu.ui.hpp"
#include "CannyMenu.ui.hpp"

InputValidator inputValidator;


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
    // clearScreen();
}

int MainMenu::displayMainMenu()
{
    int choice;
    do
    {
        cout << "\n"
             << "       * * * * * * * * * * * * * * * * * * * * * * *\n"
             << "       *                                           *\n"
             << "       *            Menu Principal                 *\n"
             << "       *                                           *\n"
             << "       *      (1) Charger une image                *\n"
             << "       *      (2) Accéder au menu de traitement    *\n"
             << "       *      (3) Sauvegarder l'image              *\n"
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

    cv::Mat image = cv::imread("C:\\Users\\tslem\\Desktop\\Laplateforme\\bachelore2\\depot\\Cpp\\projetGroupe\\Mutexisation\\CPMULTI\\assets\\image.jpg");

    switch (userChoice)
    {
    case 1:
        cout << "You chose: Canny Edge Detection" << endl; // Debug
        
        if (image.empty()) {
            std::cerr << "Erreur: Impossible de charger l'image " << "C:\\Users\\tslem\\Desktop\\Laplateforme\\bachelore2\\depot\\Cpp\\projetGroupe\\Mutexisation\\CPMULTI\\assets\\image.jpg" << std::endl;
            break;
        }
        CannyMenu cannyMenu;
        cannyMenu.cannyMenu(image);
    case 2:
        cout << "You chose: Denoising" << endl; // Debug
        break;
    case 3:
        cout << "You chose: Fourier Transform" << endl; // Debug
        break;
    case 4:
        cout << "You chose: Gaussian Blur" << endl; // Debug
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

void MainMenu::handleMenuChoice(int userChoice)
{

    // clearScreen();

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
        cout << "You chose: Charger une image" << endl; // Debug
        break;
    case 2:
        cout << "You chose: Accéder au menu de traitement" << endl; // Debug
        userChoice = displayProcessingMenu();
        handleProcessingChoice(userChoice);
    case 3:
        cout << "You chose: Sauvegarder l'image" << endl; // Debug
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