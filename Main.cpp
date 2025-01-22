#include "include/TerminalDisplay.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    TerminalDisplay terminalDisplay;
    int userMenuChoice = terminalDisplay.displayMenu();
    terminalDisplay.handleMenuChoice(userMenuChoice);
}
