#include "CheckInputWithMessage.h"

/*
    Clear screen and show message if input was incorrect
*/

void checkInputWithMessage() {
    extern bool badInput;

    system("clear");
    if(badInput){
        std::cout << "Неправильный ввод\n\n";
        badInput = false;
    }
    else{
        std::cout << "\n\n";
    }
    
}