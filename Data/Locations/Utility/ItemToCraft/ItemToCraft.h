#ifndef GAME_ITEMTOCRAFT_H
#define GAME_ITEMTOCRAFT_H

#include "../ReagentElement/ReagentElement.h"
#include <vector>

class ItemToCraft {
        friend class Workshop;
        std::vector<ReagentElement> m_reagents;
        const int m_itemId;
    public:
        ItemToCraft(const int, std::vector<ReagentElement>);
};

#endif //GAME_ITEMTOCRAFT_H