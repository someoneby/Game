#include "IEquipment.h"
#include "../../Characters/Player/Player.h"
#include "../../Equipment/Helm/Helm.h"

void IEquipment::equip(){
    if(EquipedItems::getHelm() != nullptr)
        EquipedItems::getHelm()->unEquip;
    
    EquipedItems::equipHelm(this);    
}

void IEquipment::unEquip(){
    int sum = 0;
}