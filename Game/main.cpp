#include <iostream>
#include "Characters/Player/Player.h"
#include "Characters/Mob/Mob.h"

int main() {

    Player * player = new Player();
    player->setName("PIDOR");
    Mob * mob = new Mob();

    player->fight(mob);


}
