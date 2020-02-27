#include <iostream>
#include "Characters/Player/Player.h"
#include "Characters/Mob/Mob.h"

int main() {

    // Player * player = Player::getInstance();
    // player->setName("PIFOR");
    
    Helm * helm = new Helm(1,1.0,1);
    Helm * helm2 = new Helm(10,10.0,10);
    EquipedItems::equipHelm(helm);
    EquipedItems::printHelm();
    EquipedItems::equipHelm(helm2);
    EquipedItems::printHelm();

}
