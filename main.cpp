#include <iostream>
#include "Data/Characters/Player/Player.h"
#include "Data/Characters/Mob/Mob.h"
#include "Data/GameInterface/Bag/Bag.h"
#include "Data/Items/Helm/Helm.h"
#include "Data/Items/Utility/AllItemsDB/AllItemsDB.h"
#include "Data/GameInterface/EquipedItems/EquipedItems.h"
#include "Data/GameInterface/MainMenu/MainMenu.h"
#include "Data/GameInterface/LocationsMenu/LocationsMenu.h"

using namespace std;

int main() {
    EquipedItems::equip(2);
    Bag::putToBag(5,10);
    Bag::putToBag(1,10);
    Bag::putToBag(3,10);
    MainMenu::showMainMenu();    
    

}
