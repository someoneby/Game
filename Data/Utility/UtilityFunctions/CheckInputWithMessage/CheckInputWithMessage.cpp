#include "CheckInputWithMessage.h"


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