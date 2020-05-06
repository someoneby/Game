#ifndef GAME_REAGENTELEMENT_H
#define GAME_REAGENTELEMENT_H


#include <vector>

/*
    This struct uses to store data about reagents and it's count 
    that needs to craft some item.
*/
struct ReagentElement {
    const int m_id;
    const int m_count;
    ReagentElement(const int id, const int number);
};


#endif //GAME_REAGENTELEMENT_H