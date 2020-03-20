#ifndef GAME_WORKSHOP_H
#define GAME_WORKSHOP_H

#include <vector>
#include "../Utility/ReagentsToCraft/ReagentsToCraft.h"

class Workshop {
        static int getAvailableNumber(int);
        static void showReagents(int);
        static void craftMenu(int);

        static std::vector<ReagentsToCraft *> m_items;
    public:
        static void showItemsToCraft();

};

#endif //GAME_WORKSHOP_H