#ifndef GAME_IUNIT_H
#define GAME_IUNIT_H


class IUnit {
public:
    virtual ~IUnit();
    IUnit() = default;

    virtual bool isMissing() = 0;
    virtual bool isCritical() = 0;
    virtual float getArmor() = 0;
    virtual int getHP() = 0;
    virtual int damageCalculating(float) = 0;
    virtual void hit(IUnit *) = 0;

};


#endif //GAME_IUNIT_H
