#ifndef TERMINALDISPLAY_HPP
#define TERMINALDISPLAY_HPP
#include "InputValidator.hpp"
#include "CannyEdgeDetection.hpp"
#include "GaussianBlurProcessor.hpp"
#include <iostream>
using namespace std;
#include <limits>
#include <iomanip> 
#include <string>

class TerminalDisplay {
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

    void handleMenuChoice(int userMenuChoice);

private:

    /** 
    * Function is user to clear the terminal screen
    */
    void clearScreen(){printf("\033c");};

};

#endif // TERMINALDISPLAY_HPP
