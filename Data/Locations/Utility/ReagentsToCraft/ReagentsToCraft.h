#ifndef GAME_REAGENTSTOCRAFT_H
#define GAME_REAGENTSTOCRAFT_H

#include "../ReagentElement/ReagentElement.h"
#include <vector>

class ReagentsToCraft {
        friend class Workshop;
        std::vector<ReagentElement> * m_reagents;
        int m_itemId;
    public:
        ReagentsToCraft(int, std::vector<ReagentElement> *);
};

#endif //GAME_REAGENTSTOCRAFT_H