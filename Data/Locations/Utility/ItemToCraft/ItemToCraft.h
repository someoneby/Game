#ifndef GAME_ITEMTOCRAFT_H
#define GAME_ITEMTOCRAFT_H

/*
    This struct store data about item and which reagents it needs to 
    be crafted
*/

#include "../ReagentElement/ReagentElement.h"
#include <vector>

struct ItemToCraft {
        std::vector<ReagentElement> m_reagents;
        const int m_itemId;
        ItemToCraft(const int, std::vector<ReagentElement>);
};

#endif //GAME_ITEMTOCRAFT_H