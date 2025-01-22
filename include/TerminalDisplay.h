#ifndef TERMINALDISPLAY_H
#define TERMINALDISPLAY_H
#include "../include/InputValidator.h"
#include <iostream>
using namespace std;

class TerminalDisplay
{
public:
    /** Function to display a welcome message
     */
    void displayWelcomeMessage();

    /** Function to display the menu options et get user's choice
     * @return int choice
     */

    int displayMenu();
    /** Function to display the Gaussian Blur sub menu options et get user's choice
     * @return int choice
     */
    int displaySubMenuGaussian();

private:
    /** InputValidator object to validate user input
     */
    InputValidator inputValidator;
};

#endif // TERMINALDISPLAY_H
