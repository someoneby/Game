#include "Player.h"
#include "../Utility/ParametersDB/ParametersDB.h"
#include "../Utility/Parameters/Parameters.h"
#include "../../Utility/UtilityFunctions/CombatLog/CombatLog.h"
#include "../Utility/CharConstants.h"

Player* Player::m_instance = new Player();
int Player::m_energy = CharConstants::MAX_ENERGY;

Player::Player() {
    Parameters param {CharConstants::PLAYER};
    m_hp = param.m_hp * 100000;
    m_armor = param.m_armor;
    m_avoidChance = param.m_avoidChance;
    m_damage = param.m_damage;
    m_criticalChance = param.m_critChance;
    m_name = param.m_name;
}

void Player::setName(string s_name) {
    m_instance->m_name = s_name;
}

bool Player::fight(IUnit* mob) {
    system("clear");

    combatLog(CombatLogStages::START, m_instance, mob);

    while (m_instance->m_hp != 0 && mob->getHP() != 0){
        combatLog(CombatLogStages::NEXT_ROUND, m_instance, mob);

        m_instance->hit(mob);
        mob->hit(m_instance);
    }

    if(m_instance->m_hp == 0){
        combatLog(CombatLogStages::LOSE);
        return false;
    } else {
        combatLog(CombatLogStages::WIN);
        return true;
    }
}

void Player::changeDamage(int s_damageChange){
    m_instance->m_damage += s_damageChange;
}

void Player::changeCriticalChance(float s_criticalCnahceChange){
    m_instance->m_criticalChance += s_criticalCnahceChange;
}

void Player::changeHp(int s_hpChange) {
    m_instance->m_hp += s_hpChange;
}

void Player::changeAvoidChance(float s_avoidChanceChange) {
    m_instance->m_avoidChance += s_avoidChanceChange;
}

void Player::changeArmor(int s_armorChange) {
    m_instance->m_armor += s_armorChange;
}

Player* Player::getInstance() {
    return m_instance;
}

int Player::getEnergy() {



    return m_energy;
}

void Player::spendEnergy(const int s_energy) {
    m_energy -= s_energy;
}