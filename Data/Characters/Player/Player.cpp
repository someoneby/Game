#include "Player.h"
#include "../Utility/ParametersDB/ParametersDB.h"
#include "../../Utility/UtilityFunctions/CombatLog/CombatLog.h"
#include "../Utility/CharConstants.h"

Player* Player::m_instance = new Player();
Energy Player::m_energy = Energy(CharConstants::MAX_ENERGY);


Player::Player() noexcept: IUnit(CharConstants::PLAYER) {}


/*
    Battle starting. Player and mob hit each other until someone dies.
*/
bool Player::fight(IUnit* const s_mob) noexcept {
    system("clear");

    // Battle start log
    combatLog(CombatLogStages::START, m_instance, s_mob);

    // Hit each other
    while (m_instance->m_hp != 0 && s_mob->getHP() != 0){
        combatLog(CombatLogStages::NEXT_ROUND, m_instance, s_mob);

        m_instance->hit(s_mob);
        s_mob->hit(m_instance);
    }

    // Check who died
    if(m_instance->m_hp == 0){
        combatLog(CombatLogStages::LOSE);
        return CombatLogStages::LOSE;
    } else {
        combatLog(CombatLogStages::WIN);
        return CombatLogStages::WIN;
    }
}