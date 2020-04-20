#ifndef GAME_REAGENT_H
#define GAME_REAGENT_H

#include "../IItem/IItem.h"

class Reagent : public IItem {
    public:
        Reagent(int, std::string, std::string, int);
        void showDescription() const override;
};


#endif //GAME_REAGENT_H
