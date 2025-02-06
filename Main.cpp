#include "include/TerminalDisplay.hpp"
#include "MainMenu.ui.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
MainMenu mainMenu;
int main()
{
    // TerminalDisplay terminalDisplay;
    // terminalDisplay.start();
    mainMenu.mainMenu();
    return 0;
}
