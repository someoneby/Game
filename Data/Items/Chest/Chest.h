#ifndef GAME_CHEST_H
#define GAME_CHEST_H


#include "../Armor/Armor.h"

class Chest : public Armor {
    public:
        Chest(const int id, const std::string name, const int armor, const float avoidChance, const int hp,
            const int prise, const std::string description) noexcept;
};


#endif //GAME_CHEST_H
