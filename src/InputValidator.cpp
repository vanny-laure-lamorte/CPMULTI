#include "../include/InputValidator.h"
#include <iostream>
using namespace std;

bool InputValidator::isValidDigit(int userInput){
    if (userInput >= 0 && userInput <= 8){
        return true;
    }
    else
    {
        cout << "\n> Please select a valid option :( \n";
        return false;
    }
}