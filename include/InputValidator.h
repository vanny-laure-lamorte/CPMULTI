#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <string>
#include <regex>

class InputValidator {
public:

    /** Validate only numbers between 0 and X (max option)
    * @param int userInput
    * @param int maxOption
    * @return bool userInput
    */
   bool isValidDigit(int userInput, int maxOption); 
    
private:

};

#endif // INPUTVALIDATOR_H
