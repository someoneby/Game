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
        static void setName(string name);
        static bool fight(IUnit* mob);
        static void changeDamage(int damage);
        static void changeCriticalChance(float critChance);
        static void changeHp(int hp);
        static void changeAvoidChance(float avoidChance);
        static void changeArmor(int armor);
};


#endif //GAME_PLAYER_H
