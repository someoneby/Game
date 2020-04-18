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
        static void spendEnergy(const int);
        static void setName(string name);
        static bool fight(IUnit*);
        static void changeDamage(int);
        static void changeCriticalChance(float);
        static void changeHp(int);
        static void changeAvoidChance(float);
        static void changeArmor(int);
};


#endif //GAME_PLAYER_H
