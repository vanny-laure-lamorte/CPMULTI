#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include "InputValidator.hpp"
#include "CannyMenu.ui.hpp"

using namespace std;


class MainMenu
{
    public:
        /**
         * Function serves as the main control loop of the application.  
         * The loop terminates when the user chooses option 9 to quit the program.
         */
        void mainMenu();
        /**
         * Function to display a welcome message
         */
        void displayWelcomeMessage();

        /**
         * Function to display the menu options et get user's choice
         * @return int choice
         */
        int displayMainMenu();

                /**
         * Function to display the menu options et get user's choice
         * @return int choice
         */
        int displayProcessingMenu();

        /**
         * Function to display a rectangle with a title
         * @param string text
         */
        void displayRectangleWithTitle(string text);

        /**
         * Function takes an integer input representing the user's choice from the menu.
         * It clears the terminal screen, displays the title of the selected menu option a
         * @param int userMenuChoice
         */
        void handleProcessingChoice(int userMenuChoice);

                /**
         * Function takes an integer input representing the user's choice from the menu.
         * It clears the terminal screen, displays the title of the selected menu option a
         * @param int userMenuChoice
         */
        void handleMenuChoice(int userMenuChoice);

        /**
         * @brief 
         * 
         * @return int 
         */
        int gaussianSubmenuChoice();

        /**
         * Function takes an integer input representing the user's choice from the submenu. 
         * It clears the terminal screen and performs the corresponding image processing operation.
         * @param int subMenuChoice
         */
        int handleGaussianSubmenuChoice(int submenuChoice);

        int gaussianKernelSubmenuChoice();

        private:
    /**
     * Function is user to clear the terminal screen
     */
    void clearScreen() { printf("\033c"); }
};

#endif // MAINMENU_HPP