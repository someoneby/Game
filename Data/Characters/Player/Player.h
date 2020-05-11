#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "../IUnit/IUnit.h"
#include "../Utility/Energy/Energy.h"

class Player : public IUnit {
    private:
        static Energy m_energy;
        static Player* m_instance;
        Player() noexcept;
    public:
        static bool fight(IUnit* const mob) noexcept;
        
        static void changeDamage(const int damage) noexcept { m_instance->m_damage += damage; };
        static void changeCriticalChance(const float critChance) noexcept { m_instance->m_criticalChance += critChance; };
        static void changeHp(const int hp) noexcept { m_instance->m_hp += hp; };
        static void changeAvoidChance(const float avoidChance) noexcept { m_instance->m_avoidChance += avoidChance; };
        static void changeArmor(const int armor) noexcept { m_instance->m_armor += armor; };
        static Player* getInstance() noexcept { return m_instance; };
        static void setName(const string name) noexcept { m_instance->m_name = name; };
        static int getEnergy() noexcept { return m_energy.getEnergy(); };
        static void spendEnergy(const int energy) noexcept { m_energy.spendEnergy(energy); };
};


#endif //GAME_PLAYER_H
