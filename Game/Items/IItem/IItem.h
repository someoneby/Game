#ifndef GAME_IITEM_H
#define GAME_IITEM_H

#include <iostream>

class IItem {
    public:
        virtual void show() = 0;
        virtual int getId() = 0;
        virtual std::string getName() = 0;
};

#endif