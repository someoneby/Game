#ifndef GAME_REAGENT_H
#define GAME_REAGENT_H

#include "../IItem/IItem.h"

class Reagent : public IItem {
    public:
        Reagent(const int, const std::string, const std::string, const int) noexcept;
        void showDescription() const noexcept override { std::cout << m_name << "\n\n" << m_description;};
};


#endif //GAME_REAGENT_H
