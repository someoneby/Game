#ifndef GAME_HELM_H
#define GAME_HELM_H


#include "../Armor/Armor.h"

class Helm : public Armor {
    public:
        Helm(int id, std::string name, int armor, float avoidChance, int hp, int prise, std::string description);
};


#endif //GAME_HELM_H
