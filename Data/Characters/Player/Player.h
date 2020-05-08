#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "../IUnit/IUnit.h"
#include "../Utility/Energy/Energy.h"

class Player : public IUnit {
    private:
        static Energy m_energy;
        static Player* m_instance;
        Player();
    public:
        static bool fight(IUnit* const mob);
        
        static void changeDamage(const int damage) { m_instance->m_damage += damage; };
        static void changeCriticalChance(const float critChance) { m_instance->m_criticalChance += critChance; };
        static void changeHp(const int hp) { m_instance->m_hp += hp; };
        static void changeAvoidChance(const float avoidChance) { m_instance->m_avoidChance += avoidChance; };
        static void changeArmor(const int armor) { m_instance->m_armor += armor; };
        static Player* getInstance() { return m_instance; };
        static void setName(const string name) { m_instance->m_name = name; };
        static int getEnergy() { return m_energy.getEnergy(); };
        static void spendEnergy(const int energy) { m_energy.spendEnergy(energy); };
};


#endif //GAME_PLAYER_H
