#include "../include/InputValidator.h"
#include <iostream>
using namespace std;

bool InputValidator::isValidDigit(int userInput, int maxOption){
    if (userInput >= 0 && userInput <= maxOption){
        return true;
    }
    else
    {
        cout << "\n> Please select a valid option :( \n";
        return false;
    }
}