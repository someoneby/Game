#ifndef GAME_REAGENTELEMENT_H
#define GAME_REAGENTELEMENT_H

#include <vector>

class ReagentElement {
        int m_id;
        int m_count;
    public:
        ReagentElement(int, int);
        int getId();
        int getCount();
};


#endif //GAME_REAGENTELEMENT_H