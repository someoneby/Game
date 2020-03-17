#ifndef GAME_WORKSHOP_H
#define GAME_WORKSHOP_H

#include <vector>
#include "../Utility/ReagentsToCraft/ReagentsToCraft.h"

class Workshop {
        int getAvailableNumber();
        void craftMenu(int);

        static std::vector<ReagentsToCraft> m_items;
    public:
        void showItemsToCraft();

};

#endif //GAME_WORKSHOP_H