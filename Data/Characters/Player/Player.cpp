#include "Player.h"
#include "../Utility/ParametersDB/ParametersDB.h"
#include "../Utility/Parameters/Parameters.h"
#include "../../Utility/UtilityFunctions/CombatLog/CombatLog.h"
#include "../Utility/CharConstants.h"

Player* Player::m_instance = new Player();

Player::Player() {
    Parameters param {CharConstants::player};
    m_hp = param.m_hp;
    m_armor = param.m_armor;
    m_avoidChance = param.m_avoidChance;
    m_damage = param.m_damage;
    m_criticalChance = param.m_critChance;
    m_name = param.m_name;
}

void Player::setName(string s_name) {
    m_instance->m_name = s_name;
}

void Player::fight(IUnit* mob) {

    combatLog(CombatLogStages::START, m_instance, mob);

    while (m_instance->m_hp != 0 && mob->getHP() != 0){
        combatLog(CombatLogStages::NEXT_ROUND, m_instance, mob);

        m_instance->hit(mob);
        mob->hit(m_instance);
    }

    if(m_instance->m_hp == 0){
        combatLog(CombatLogStages::LOSE);
    } else {
        combatLog(CombatLogStages::WIN);
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