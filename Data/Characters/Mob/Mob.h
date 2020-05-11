#ifndef GAME_MOB_H
#define GAME_MOB_H

#include "../IUnit/IUnit.h"

class Mob : public IUnit {
    public:
        Mob(const int hp, const float armor, const float avoidChance, const int damage,
            const float critChance, const string& name) noexcept;
};


#endif //GAME_MOB_H
