#ifndef GAME_REAGENTELEMENT_H
#define GAME_REAGENTELEMENT_H

/*
    This struct uses to store data about material and it`s count 
    that needs to craft some item
*/

#include <vector>

struct ReagentElement {
        const int m_id;
        const int m_count;
        ReagentElement(const int, const int);
};


#endif //GAME_REAGENTELEMENT_H