#include "CheckInputWithMessage.h"

/*
    Clears screen and shows error message if input was incorrect.
*/
void checkInputWithMessage() {
    extern bool badInput;

    system("clear");
    if(badInput){
        std::cout << "Неправильный ввод\n";
        badInput = false;
    }
    else{
        std::cout << "\n";
    }
    
}