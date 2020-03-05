#include <iostream>
#include "CombatLog.h"
using std::cout;
using std::endl;

void combatLog (CombatLogStages action, IUnit * unit, IUnit * target, int damage) {
    cout << endl;

    switch (action) {
        case CombatLogStages::start : {
            cout << "Начинается бой между " << unit->getName() << " и " << target->getName();
            break;
        }
        case CombatLogStages::nextRound : {
            cout << endl << " " << unit->getName() << " HP: " << unit->getHP()
                << endl << " " << target->getName() << " HP: " << target->getHP() << endl;
            break;
        }
        case CombatLogStages::missing : {
            cout << " " << unit->getName() << " собирает все силы в кулак и делает ацкий удар, жалко, правда, что мимо. ";
            break;
        }
        case CombatLogStages::critical : {
            cout << " Бодрительный борщ от мамы придаёт сил и " << unit->getName()
                << " наносит критический удар равный " << damage << ".";
            break;
        }
        case CombatLogStages::hit : {
            cout << " " << unit->getName() << " как самый обычный студент приносит самый обычный диплом,"
                 " которым даёт по лицу " << target->getName() << " нанеся " << damage << " ед.ур.";
            break;
        }
        case CombatLogStages::lose : {
            cout << " К сожаленью ... день рожденья ... только раз в году, а у тебя так вообще больше не будет."
                    " YOU DIED!" << endl;
            break;
        }
        case CombatLogStages::win : {
            cout << endl << " You win! Пора раскатать рукава, натянуть штаны и собрать лут." << endl;
            break;
        }
    }
}

