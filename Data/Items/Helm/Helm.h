#ifndef GAME_HELM_H
#define GAME_HELM_H


#include "../Armor/Armor.h"

class Helm : public Armor {
    public:
        Helm(const int id, const std::string name, const int armor, const float avoidChance, const int hp,
            const int prise, const std::string description);
};


#endif //GAME_HELM_H
