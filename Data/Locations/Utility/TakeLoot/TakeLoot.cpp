#include "TakeLoot.h"
#include "../../../Items/Utility/AllItemsDB/AllItemsDB.h"
#include "../../../GameInterface/Bag/Bag.h"
#include "../../../Utility/UtilityFunctions/RandDouble/RandDouble.h"
#include "../LocationConstants.h"

#include <iostream>
using namespace std;

void takeLoot(const int s_level) { 
    cout << "\n Ваша добыча:\n  ";

    bool reagentDrop { randDouble() < LocationConstants::DROP_CHANCE};

    if(reagentDrop) {
        int numb {AllItemsDB::getReagentsNumber() };

        int lootId {LocationConstants::FIRST_REAGENT_ID + (int)(randDouble() * 100) % numb};
        Bag::putToBag(lootId);
        cout << AllItemsDB::getItemByID(lootId)->getName() << "\n  ";
    }

    int gold {100 + ((s_level * 10) * randDouble())};
    Bag::takeGold(gold);
    cout << "Золото: " << gold; 
}