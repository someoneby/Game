#ifndef GAME_COMBATLOG_H
#define GAME_COMBATLOG_H


#include "../Constans/CombatLogStages.h"
#include "../../Characters/IUnit/IUnit.h"

void combatLog (CombatLogStages, IUnit * = nullptr, IUnit * = nullptr, int = 0);


#endif //GAME_COMBATLOG_H
