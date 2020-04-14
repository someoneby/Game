#ifndef GAME_COMBATLOG_H
#define GAME_COMBATLOG_H

/*
    This function uses to print log for fighting
*/

#include "../../Constants/CombatLogStages.h"
#include "../../../Characters/IUnit/IUnit.h"

void combatLog (const CombatLogStages, IUnit* const = nullptr, IUnit* const = nullptr, const int = 0);


#endif //GAME_COMBATLOG_H
