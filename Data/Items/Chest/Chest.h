#ifndef GAME_CHEST_H
#define GAME_CHEST_H


#include "../Armor/Armor.h"

class Chest : public Armor {
    public:
        Chest(int id, std::string name, int armor, float avoidChance, int hp, int prise, std::string description);
};


#endif //GAME_CHEST_H
