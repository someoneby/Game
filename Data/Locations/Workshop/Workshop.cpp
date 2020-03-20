#include "Workshop.h"
#include "../../Utility/AllItemsDB/AllItemsDB.h"
#include "../../Utility/UtilityFunctions/GetChoise/GetChoise.h"
#include "../../Utility/UtilityFunctions/CheckInputWithMessage/CheckInputWithMessage.h"
#include "../../Utility/UtilityFunctions/BadInputState/BadInputState.h"
#include "../../GameInterface/Bag/Bag.h"
#include <iostream>
using std::cout;
using std::cin;

//ReagentsToCraft(int, std::vector<ReagentElement>);
std::vector<ReagentsToCraft *> Workshop::m_items {
    new ReagentsToCraft(33, new std::vector<ReagentElement> {ReagentElement(91,2), ReagentElement(92,3)})
};

void Workshop::showItemsToCraft() {
    int choise {1};

    while(choise != 0) {
        checkInputWithMessage();

        //Show list of items to craft
        cout << "\nВы можете создать: \n\n";
        for(int i{0}; i < m_items.size(); ++i){
            cout << i+1 << ". " << AllItemsDB::getItemByID(m_items.at(i)->m_itemId)->getName()
                << " - " << getAvailableNumber(i) << ".\n";
        }

        cout <<"\n0. Выход" << "\nВаш выбор: ";
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
        AllItemsDB::getItemByID(m_items.at(s_position)->m_itemId)->showDescription();
        cout << "\n\nРеагенты:\n";
        showReagents(s_position);

        int availableNumber {getAvailableNumber(s_position)};
        cout << "\nВы можете создать: " << availableNumber
            << "\nСколько создать (0-выход): ";

        choise = getChoise();

        if(choise > 0 && choise <= availableNumber){
            Bag::putToBag(m_items.at(s_position)->m_itemId, choise);

            for(int i {0}; i < m_items.at(s_position)->m_reagents->size(); ++i) {
                int id {m_items.at(s_position)->m_reagents->at(i).getId()};
                int count {m_items.at(s_position)->m_reagents->at(i).getCount()};

                Bag::takeFromBag(id, count * choise);
            }
            return;
        } 
        else if (choise == 0)
            return;
        else
            badInputState();
    }
}

int Workshop::getAvailableNumber(int s_position) {
    int availableNumber;
    for(int i{0}; i < m_items.at(s_position)->m_reagents->size(); ++i) {
        int nededCount {m_items.at(s_position)->m_reagents->at(i).getCount()};
        int existCount {Bag::getCounterById(m_items.at(s_position)->m_reagents->at(i).getId())};

        int tempAvailableNumber = existCount / nededCount;

        if(tempAvailableNumber == 0)
            return tempAvailableNumber;
        if(tempAvailableNumber < availableNumber)
            availableNumber = tempAvailableNumber;
        else if(i == 1)
            availableNumber = tempAvailableNumber;
    }
    return availableNumber;
}

void Workshop::showReagents(int s_position) {
    for(int i {0}; i < m_items.at(s_position)->m_reagents->size(); ++i){
        cout << AllItemsDB::getItemByID(m_items.at(s_position)->m_reagents->at(i).getId())->getName()
            << " " << m_items.at(s_position)->m_reagents->at(i).getCount() << ".\n";
    }
}