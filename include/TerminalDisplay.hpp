#ifndef TERMINALDISPLAY_HPP
#define TERMINALDISPLAY_HPP
#include "InputValidator.hpp"
// #include "CannyEdgeDetection.hpp"
#include "GaussianBlurProcessor.hpp"
#include "DiscreteFourierTransform.hpp"
#include <iostream>
using namespace std;
#include <limits>
#include <iomanip>
#include <string>

class TerminalDisplay
{
public:
    /**
     * Function to display a welcome message
     */
    void displayWelcomeMessage();

    /**
     * Function to display the menu options et get user's choice
     * @return int choice
     */
    int displayMenu();

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
    void handleMenuChoice(int userMenuChoice);

    /**
     * Function takes an integer input representing the user's choice from the submenu. 
     * It clears the terminal screen and performs the corresponding image processing operation.
     * @param int subMenuChoice
     */
    int handleSubmenuChoice(int submenuChoice);

    /**
     * Function
     */
    int submenuChoice();

    void start();

private:
    /**
     * Function is user to clear the terminal screen
     */
    void clearScreen() { printf("\033c"); }
};

#endif // TERMINALDISPLAY_HPP
