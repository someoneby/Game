#ifndef GAME_MOBFACTORT_H
#define GAME_MOBFACTORT_H

#include "../Mob/Mob.h"

class MobFactory {
    public:
        static Mob* getMob(const int depthLevel);
};

#endif //GAME_MOBFACTORT_H