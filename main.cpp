#include <iostream>
#include "Game/Characters/Player/Player.h"
#include "Game/Characters/Mob/Mob.h"
#include "Game/GameInterface/Bag/Bag.h"

int main() {

    // Player * player = Player::getInstance();
    // player->setName("PIFOR");
    Bag::putToBag(0);
    Bag::show();
    Bag::putToBag(0);
    Bag::putToBag(0);
    Bag::putToBag(2);
    Bag::show();


}
