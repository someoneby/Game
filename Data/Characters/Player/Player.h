#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "../IUnit/IUnit.h"

class Player : public IUnit {
    private:
        static int m_energy;
        static Player* m_instance;
        Player();
    public:
        static Player* getInstance();
        static int getEnergy();
        static void spendEnergy(const int energy);
        static void setName(const string name);
        static bool fight(IUnit* const mob);
        static void changeDamage(const int damage);
        static void changeCriticalChance(const float critChance);
        static void changeHp(const int hp);
        static void changeAvoidChance(const float avoidChance);
        static void changeArmor(const int armor);
};


#endif //GAME_PLAYER_H
