#include "Player.h"
#include "../Utility/ParametersDB/ParametersDB.h"
#include "../Utility/Parameters/Parameters.h"
#include "../../Utility/UtilityFunctions/CombatLog/CombatLog.h"
#include "../Utility/CharConstants.h"

Player* Player::m_instance = new Player();
int Player::m_energy = CharConstants::MAX_ENERGY;

Player::Player() {
    Parameters param {CharConstants::PLAYER};

    m_hp = param.m_hp * 100000; //for testing
    m_armor = param.m_armor;
    m_avoidChance = param.m_avoidChance;
    m_damage = param.m_damage;
    m_criticalChance = param.m_critChance;
    m_name = param.m_name;
}

/*
    Battle starting. Player and mob hit each other until someone dies.
*/
bool Player::fight(IUnit* s_mob) {
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
        return false;
    } else {
        combatLog(CombatLogStages::WIN);
        return true;
    }
}

/*
    Change damage of the player when something changes in equipment.
*/
void Player::changeDamage(int s_damageChange){
    m_instance->m_damage += s_damageChange;
}

/*
    Change critical chance of the player when something changes in equipment.
*/
void Player::changeCriticalChance(float s_criticalCnahceChange){
    m_instance->m_criticalChance += s_criticalCnahceChange;
}

/*
    Change hp of the player when something changes in equipment.
*/
void Player::changeHp(int s_hpChange) {
    m_instance->m_hp += s_hpChange;
}

/*
    Change avoid chance of the player when something changes in equipment.
*/
void Player::changeAvoidChance(float s_avoidChanceChange) {
    m_instance->m_avoidChance += s_avoidChanceChange;
}

/*
    Change armor of the player when something changes in equipment.
*/
void Player::changeArmor(int s_armorChange) {
    m_instance->m_armor += s_armorChange;
}

/*
    Return instance of the player.
*/
Player* Player::getInstance() {
    return m_instance;
}

/*
    Calculating current energy and return it.
*/
int Player::getEnergy() {



    return m_energy;
}

/*
    Change current energy when it deeded.
*/
void Player::spendEnergy(const int s_energy) {
    m_energy -= s_energy;
}

/*
    Set name of the player in new game.
*/
void Player::setName(string s_name) {
    m_instance->m_name = s_name;
}