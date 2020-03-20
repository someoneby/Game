#ifndef GAME_REAGENT_H
#define GAME_REAGENT_H

#include "../Item/Item.h"
class Reagent : public Item {
    public:
        Reagent(int, std::string, std::string, int);
        void showDescription() override;
};


#endif //GAME_REAGENT_H
