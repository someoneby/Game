#ifndef GAME_MOB_H
#define GAME_MOB_H

#include "../IUnit/IUnit.h"

class Mob : public IUnit {
    public:
        Mob(const int, const double, const double, const int, const double, const string);
};


#endif //GAME_MOB_H
