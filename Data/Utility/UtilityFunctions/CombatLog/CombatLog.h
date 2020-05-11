#ifndef GAME_COMBATLOG_H
#define GAME_COMBATLOG_H

#include "../../Constants/CombatLogStages.h"
#include "../../../Characters/IUnit/IUnit.h"


/*
    This function uses to print log for fighting
*/
void combatLog (const CombatLogStages, const IUnit* const = nullptr, const IUnit* const = nullptr,
    const int = 0) noexcept;


#endif //GAME_COMBATLOG_H
