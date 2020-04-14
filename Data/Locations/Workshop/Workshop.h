#ifndef GAME_WORKSHOP_H
#define GAME_WORKSHOP_H

/*
    This is location where you can craft items
*/

#include <vector>
#include "../Utility/ItemToCraft/ItemToCraft.h"

class Workshop {
        static int getAvailableNumber(const int);
        static void showReagents(const int);
        static void craftMenu(const int);

        std::vector<ItemToCraft> m_items;
        static Workshop* m_instance;
        Workshop();
    public:
        static void showItemsToCraft();
};

#endif //GAME_WORKSHOP_H