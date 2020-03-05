#ifndef GAME_HELM_H
#define GAME_HELM_H


#include "../Armor/Armor.h"

class Helm : public Armor {
    public:
        Helm(int, std::string, int, float, int);
        int getHP();
        // void equip(int) override; 
};


#endif //GAME_HELM_H
