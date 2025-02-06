#include "InputValidator.hpp"
#include <iostream>
using namespace std;

bool InputValidator::isValidDigit(int userInput, int maxOption){
    if(!isdigit(userInput)){
        if (userInput >= 0 && userInput <= maxOption){
            return true;
        }
        else
        {
            cout << "\n> Please select a valid option :( \n";
            return false;
        }
    } return false;
}