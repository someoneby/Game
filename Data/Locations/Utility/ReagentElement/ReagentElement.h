#ifndef GAME_REAGENTELEMENT_H
#define GAME_REAGENTELEMENT_H

#include <vector>

class ReagentElement {
        const int m_id;
        const int m_count;
    public:
        ReagentElement(const int, const int);
        int getId();
        int getCount();
};


#endif //GAME_REAGENTELEMENT_H