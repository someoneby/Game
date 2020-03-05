#include <iostream>
#include "Data/Characters/Player/Player.h"
#include "Data/Characters/Mob/Mob.h"
#include "Data/GameInterface/Bag/Bag.h"
#include "Data/Items/Helm/Helm.h"
#include "Data/Utility/AllItemsDB/AllItemsDB.h"
#include "Data/GameInterface/EquipedItems/EquipedItems.h"

using namespace std;

int main() {

    Bag::putToBag (1);
    Bag::putToBag (1);
    Bag::putToBag (1);
    // Bag::putToBag (2);
    Bag::putToBag (3);
    Bag::show();


    

}
