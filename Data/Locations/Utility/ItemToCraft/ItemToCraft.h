#ifndef GAME_ITEMTOCRAFT_H
#define GAME_ITEMTOCRAFT_H


#include "../ReagentElement/ReagentElement.h"
#include <vector>

/*
    This struct store data about item and which reagents it needs to 
    be crafted
*/
struct ItemToCraft {
        std::vector<ReagentElement> m_reagents;
        const int m_itemId;
        ItemToCraft(const int itemId, std::vector<ReagentElement> reagentList) noexcept;
};

#endif //GAME_ITEMTOCRAFT_H