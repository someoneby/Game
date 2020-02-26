#include <iostream>
#include "Characters/Player/Player.h"
#include "Characters/Mob/Mob.h"

int main() {

    // Player * player = Player::getInstance();
    // player->setName("PIFOR");
    
    Helm * helm = new Helm();
    helm->equip();

}
