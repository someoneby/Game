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
    int pause;
    Bag::takeGold(10000);
    Bag::show();
    cin >> pause;
    // MainMenu::showMainMenu();
    LocationsMenu::showLocations();

    Bag::show();



    

}
