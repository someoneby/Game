#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "../Unit/Unit.h"
#include "../IUnit/IUnit.h"
#include "../../GameInterface/EquipedItems/EquipedItems.h"
#include "../../GameInterface/Bag/Bag.h"

class Player : public Unit {
    private:
        static Player * m_instance;
        Player();
        Player(const Player&);
        Player& operator = (Player&);

    public:
        static Player * getInstance();
        void setName(string name);

        void fight(IUnit *);

};


#endif //GAME_PLAYER_H
