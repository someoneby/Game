#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "../Unit/Unit.h"
#include "../IUnit/IUnit.h"

class Player : public Unit {
public:
    Player();
    void setName(string name);

    void fight(IUnit *);


};


#endif //GAME_PLAYER_H
