#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "../Unit/Unit.h"
#include "../IUnit/IUnit.h"

class Player : public Unit {
    private:
        static Player* m_instance;
        Player();
        Player(const Player&);
        Player& operator = (Player&);

    public:
        static Player* getInstance();
        void setName(string name);

        void fight(IUnit*);
        void changeDamage(int);
        void changeCriticalChance(float);
        void changeHp(int);
        void changeAvoidChance(float);
        void changeArmor(int);

};


#endif //GAME_PLAYER_H
