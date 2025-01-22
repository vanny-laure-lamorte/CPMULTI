#ifndef INPUTVALIDATOR_HPP
#define INPUTVALIDATOR_HPP

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

#endif // INPUTVALIDATOR_HPP
