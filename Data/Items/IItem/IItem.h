#ifndef GAME_IITEM_H
#define GAME_IITEM_H

#include <iostream>

class IItem {
    public:
        virtual void showDescription() const = 0;
        virtual int getId() const = 0;
        virtual std::string getName() const = 0;
        virtual int getPrise() const = 0;
};

#endif