#ifndef GAME_LOCATIONCONSTANTS_H
#define GAME_LOCATIONCONSTANTS_H

#include <vector>

namespace LocationConstants {
    const int MENU_TO_BUY = 1;
    const int MENU_TO_SELL = 2;
    const int FARM = 1;
    const int PATROL = 2;
    const int DEPTHS = 3;
    const int GO_DEEPER = 1;
    const int FIGHT = 1;
    const int BAG = 2;
    const int PERSON_MENU = 3;
    const int EXIT = 0;
    
    const int FIRST_HELM_ID_TO_BUY = 1;
    const int FIRST_CHEST_ID_TO_BUY = 31;
    const int FIRST_WEAPON_ID_TO_BUY = 61;

    const int FIRST_HELM_ID_TO_CRAFT = 3;
    const int FIRST_CHEST_ID_TO_CRAFT = 33;
    const int FIRST_WEAPON_ID_TO_CRAFT = 63;

    const int modifierCostToBuy {10};
}

#endif //GAME_LOCATIONCONSTANTS_H