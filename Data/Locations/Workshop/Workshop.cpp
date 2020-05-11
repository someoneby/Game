#include "Workshop.h"
#include "../../Items/Utility/AllItemsDB/AllItemsDB.h"
#include "../../Utility/UtilityFunctions/GetChoise/GetChoise.h"
#include "../../Utility/UtilityFunctions/CheckInputWithMessage/CheckInputWithMessage.h"
#include "../../Utility/UtilityFunctions/BadInputState/BadInputState.h"
#include "../../GameInterface/Bag/Bag.h"
#include "../Utility/LocationConstants.h"
#include <iostream>
using std::cout;
using std::cin;

Workshop* Workshop::m_instance = new Workshop();

Workshop::Workshop() noexcept : m_items{
        ItemToCraft(3, std::vector<ReagentElement> {ReagentElement(91,2), ReagentElement(92,3)}),
        ItemToCraft(5, std::vector<ReagentElement> {ReagentElement(91,2), ReagentElement(92,3)}),
        ItemToCraft(7, std::vector<ReagentElement> {ReagentElement(91,2), ReagentElement(92,3)}),
        ItemToCraft(9, std::vector<ReagentElement> {ReagentElement(91,2), ReagentElement(92,3)}),

        ItemToCraft(33, std::vector<ReagentElement> {ReagentElement(91,2), ReagentElement(92,3)}),
        ItemToCraft(35, std::vector<ReagentElement> {ReagentElement(91,2), ReagentElement(92,3)}),
        ItemToCraft(36, std::vector<ReagentElement> {ReagentElement(91,2), ReagentElement(92,3)}),
        ItemToCraft(38, std::vector<ReagentElement> {ReagentElement(91,2), ReagentElement(92,3)})
    } 
{}

/*
    This is main menu for workshop. Show list of all items that are available
    to craft.
*/
void Workshop::showItemsToCraft() noexcept {
    int choise {1};

    while(choise) {
        checkInputWithMessage();

        //Show list of items to craft
        cout << "\nВы можете создать: \n\n";
        for(int i{0}; i < m_instance->m_items.size(); ++i){
            //Show type of item for better navigation
            if(m_instance->m_items.at(i).m_itemId == LocationConstants::FIRST_HELM_ID_TO_CRAFT)
                cout << " Шлемы:\n";
            else if(m_instance->m_items.at(i).m_itemId == LocationConstants::FIRST_CHEST_ID_TO_CRAFT)
                cout << "\n Броня на тело:\n";
            else if(m_instance->m_items.at(i).m_itemId == LocationConstants::FIRST_WEAPON_ID_TO_CRAFT)
                cout << "\n Оружия:\n";

            cout << " " << i+1 << ". " << AllItemsDB::getItemByID(m_instance->m_items.at(i).m_itemId)->getName()
                << " - " << getAvailableNumber(i) << ".\n";
        }
        
        cout <<"\n0. Выход" << "\nВаш выбор: ";

        choise = getChoise();

        // number within range
        if(choise > 0 && choise <= m_instance->m_items.size()) {
            //-1 because real position "choise-1"
            craftMenu(choise-1);
        }
        else if(choise == LocationConstants::EXIT) {
            return;
        }
        //Bad input
        else
            badInputState();
    }
}

/*
    Show description of the item and possibility to craft it.
*/
void Workshop::craftMenu(const int s_position) noexcept {
    int choise {1};

    while(choise) {
        checkInputWithMessage();

        //Show information
        AllItemsDB::getItemByID(m_instance->m_items.at(s_position).m_itemId)->showDescription();
        cout << "\n\n Реагенты:\n";
        showReagents(s_position);

        int availableNumber {getAvailableNumber(s_position)};
        cout << "\nВы можете создать: " << availableNumber
            << "\nСколько создать (0-выход): ";

        choise = getChoise();

        // number within range
        if(choise > 0 && choise <= availableNumber){
            Bag::putToBag(m_instance->m_items.at(s_position).m_itemId, choise);

            for(auto reagentPtr{m_instance->m_items.at(s_position).m_reagents.begin()};
            reagentPtr != m_instance->m_items.at(s_position).m_reagents.end(); ++reagentPtr) {
                int id{(*reagentPtr).m_id};
                int count{(*reagentPtr).m_count};

                // Take reagent from bag
                Bag::takeFromBag(id, count * choise);
            }
            return;
        } 
        else if (choise == LocationConstants::EXIT)
            return;
        //Bad Input
        else
            badInputState();
    }
}

/*
    Return available number for crafting the item.
*/
int Workshop::getAvailableNumber(const int s_position) noexcept {
    int availableNumber;
    for(int i{0}; i < m_instance->m_items.at(s_position).m_reagents.size(); ++i) {
        int nededCount {m_instance->m_items.at(s_position).m_reagents.at(i).m_count};
        int existCount {Bag::getCounterById(m_instance->m_items.at(s_position).m_reagents.at(i).m_id)};

        int tempAvailableNumber = existCount / nededCount;

        if(tempAvailableNumber == 0)
            return tempAvailableNumber;
        if(tempAvailableNumber < availableNumber || i == 1)
            availableNumber = tempAvailableNumber;
    }
    return availableNumber;
}

/*
    Show reagents that needed to craft the item.
*/
void Workshop::showReagents(const int s_position) noexcept {
    for(auto reagentPtr{m_instance->m_items.at(s_position).m_reagents.begin()};
    reagentPtr != m_instance->m_items.at(s_position).m_reagents.end(); ++reagentPtr) {
        cout << " " << AllItemsDB::getItemByID((*reagentPtr).m_id)->getName()
            << " " << (*reagentPtr).m_count << ".\n";
    }
}