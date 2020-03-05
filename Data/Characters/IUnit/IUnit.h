#ifndef GAME_IUNIT_H
#define GAME_IUNIT_H

#include <iostream>
using std::string;

class IUnit {
public:
    IUnit() = default;

    IUnit(const string &getName);

    virtual bool isMissing() = 0;
    virtual bool isCritical() = 0;
    virtual float getArmor() = 0;
    virtual int getHP() = 0;
    virtual string getName() = 0;
    virtual void takeDamage(int) = 0;
    virtual int damageCalculating(float) = 0;
    virtual void hit(IUnit *) = 0;

};


#endif //GAME_IUNIT_H
