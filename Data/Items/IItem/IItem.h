#ifndef GAME_IITEM_H
#define GAME_IITEM_H

#include <iostream>

class IItem {
    public:
        virtual void showDescription() = 0;
        virtual int getId() = 0;
        virtual std::string getName() = 0;
        virtual int getPrise() = 0;
};

#endif