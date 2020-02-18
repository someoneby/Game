#ifndef GAME_IEQUIPMENT_H
#define GAME_IEQUIPMENT_H


class IEquipment {
public:
    virtual void deleteIt() = 0;
//    virtual void sellIt() = 0;
    virtual void equipIt() = 0;
    virtual void unEquipIt() = 0;
};


#endif //GAME_IEQUIPMENT_H
