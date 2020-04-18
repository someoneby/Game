#include "BadInputState.h"

bool badInput;

/*
    Mark that input was incorrect.
*/
void badInputState(){
    badInput = true;
}