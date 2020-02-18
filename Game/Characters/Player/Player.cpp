#include "Player.h"
#include "../../Utility/Constans/Parameters.h"
#include "../../Utility/CombatLog/CombatLog.h"


Player::Player() : Unit(Parameters::playerArmor, Parameters::playerHP, Parameters::playerDamage,
        Parameters::playerAvoidChance, Parameters::playerCriticalChance){ }

void Player::setName(string s_name) {
    m_name = s_name;
}

void Player::fight(IUnit * mob) {

    combatLog(CombatLogStages::start, this, mob);

    while (m_hp != 0 && mob->getHP() != 0){
        combatLog(CombatLogStages::nextRound, this, mob);

        this->hit(mob);
        mob->hit(this);
    }

    if(m_hp == 0){
        combatLog(CombatLogStages::lose);
    } else {
        combatLog(CombatLogStages::win);
    }
}
