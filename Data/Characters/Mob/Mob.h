#ifndef GAME_MOB_H
#define GAME_MOB_H

#include "../IUnit/IUnit.h"

class Mob : public IUnit {
    public:
        Mob(const int hp, const double armor, const double avoidChance, const int damage,
            const double critChance, const string name);
};


#endif //GAME_MOB_H
