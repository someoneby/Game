#include "Player.h"
#include "../../Utility/Constants/Parameters.h"
#include "../../Utility/UtilityFunctions/CombatLog/CombatLog.h"

Player * Player::m_instance = nullptr;

Player::Player() : Unit(Parameters::playerArmor, Parameters::playerHP, Parameters::playerDamage,
        Parameters::playerAvoidChance, Parameters::playerCriticalChance){ }

Player* Player::getInstance() {
    if(m_instance != nullptr){
        return m_instance;
    } else {
        m_instance = new Player();
        return m_instance;
    }
}

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

void Player::changeDamage(int s_damageChange){
    m_damage += s_damageChange;
}

void Player::changeCriticalChance(float s_criticalCnahceChange){
    m_criticalChance += s_criticalCnahceChange;
}

void Player::changeHp(int s_hpChange) {
    m_hp += s_hpChange;
}

void Player::changeAvoidChance(float s_avoidChanceChange) {
    m_avoidChance += s_avoidChanceChange;
}

void Player::changeArmor(int s_armorChange) {
    m_armor += s_armorChange;
}