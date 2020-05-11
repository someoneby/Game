#ifndef GAME_WORKSHOP_H
#define GAME_WORKSHOP_H

#include <vector>
#include "../Utility/ItemToCraft/ItemToCraft.h"

/*
    This is location where you can craft items.
*/
class Workshop {
        static int getAvailableNumber(const int) noexcept;
        static void showReagents(const int) noexcept;
        static void craftMenu(const int) noexcept;
        Workshop() noexcept;

        std::vector<ItemToCraft> m_items;
        static Workshop* m_instance;
    public:
        static void showItemsToCraft() noexcept;
};

#endif //GAME_WORKSHOP_H