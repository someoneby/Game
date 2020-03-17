#include "Workshop.h"
#include "../../Utility/AllItemsDB/AllItemsDB.h"
#include "../../Utility/UtilityFunctions/GetChoise/GetChoise.h"
#include "../../Utility/UtilityFunctions/CheckInputWithMessage/CheckInputWithMessage.h"
#include "../../Utility/UtilityFunctions/BadInputState/BadInputState.h"
#include <iostream>
using std::cout;
using std::cin;


void Workshop::showItemsToCraft() {
    int choise {1};

    while(choise != 0) {
        checkInputWithMessage();

        //Show list of items to craft
        cout << "\nВы можете создать: \n\n";
        for(int i{0}; i < m_items.size(); ++i){
            AllItemsDB::getItemByID(m_items.at(i).m_itemId)->getName();
            cout << " - " << getAvailableNumber() << ".\n";
        }

        choise = getChoise();

        if(choise > 0 && choise <= m_items.size())
            craftMenu(choise-1);
        //Exit
        else if(choise == 0)
            return;
        //Bad input
        else
            badInputState();
    }
}

void Workshop::craftMenu(int s_position) {
    int choise {1};

    while(choise != 0) {
        checkInputWithMessage();

        //Show information
        AllItemsDB::getItemByID(m_items.at(s_position).m_itemId)->showDescription();
        cout << "\n\nРеагенты:\n";
        for(int i {0}; i < m_items.at(s_position).m_reagents.size(); ++i){
            // cout << m_items.at(s_position).m_reagents.at(i)
        }

        int availableNumber {getAvailableNumber()};
        cout << "\nВы можете создать: " << availableNumber
            << "\nСколько создать (0-выход): ";

        choise = getChoise();

        if(choise > 0 && choise <= availableNumber){
            
        } 
        else if (choise == 0)
            return;
        else
            badInputState();
    }
}