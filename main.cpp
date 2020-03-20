#include <iostream>
#include "Data/Characters/Player/Player.h"
#include "Data/Characters/Mob/Mob.h"
#include "Data/GameInterface/Bag/Bag.h"
#include "Data/Items/Helm/Helm.h"
#include "Data/Utility/AllItemsDB/AllItemsDB.h"
#include "Data/GameInterface/EquipedItems/EquipedItems.h"
#include "Data/GameInterface/MainMenu/MainMenu.h"
#include "Data/GameInterface/LocationsMenu/LocationsMenu.h"

using namespace std;

int main() {
    Bag::takeGold(10000);
    Bag::putToBag(2,3);
    Bag::putToBag(3,3);
    Bag::putToBag(91,20);
    Bag::putToBag(92,20);
    LocationsMenu::showLocations();

    Bag::show();



    

}
