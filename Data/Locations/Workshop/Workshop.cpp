#include "Workshop.h"
#include "../../Utility/AllItemsDB/AllItemsDB.h"
#include "../../Utility/UtilityFunctions/GetChoise/GetChoise.h"
#include "../../Utility/UtilityFunctions/CheckInputWithMessage/CheckInputWithMessage.h"
#include "../../Utility/UtilityFunctions/BadInputState/BadInputState.h"
#include "../../GameInterface/Bag/Bag.h"
#include "../Utility/MenuChoise.h"
#include "../Utility/LocationConstants.h"
#include <iostream>
using std::cout;
using std::cin;

Workshop* Workshop::m_instance = new Workshop();

Workshop::Workshop() : m_items{
        ItemToCraft(3, std::vector<ReagentElement> {ReagentElement(91,2), ReagentElement(92,3)}),
        ItemToCraft(5, std::vector<ReagentElement> {ReagentElement(91,2), ReagentElement(92,3)}),
        ItemToCraft(7, std::vector<ReagentElement> {ReagentElement(91,2), ReagentElement(92,3)}),
        ItemToCraft(9, std::vector<ReagentElement> {ReagentElement(91,2), ReagentElement(92,3)}),

        ItemToCraft(33, std::vector<ReagentElement> {ReagentElement(91,2), ReagentElement(92,3)}),
        ItemToCraft(35, std::vector<ReagentElement> {ReagentElement(91,2), ReagentElement(92,3)}),
        ItemToCraft(36, std::vector<ReagentElement> {ReagentElement(91,2), ReagentElement(92,3)}),
        ItemToCraft(38, std::vector<ReagentElement> {ReagentElement(91,2), ReagentElement(92,3)})
        // ItemToCraft(33, std::vector<ReagentElement> {ReagentElement(91,2), ReagentElement(92,3)}),
        // ItemToCraft(33, std::vector<ReagentElement> {ReagentElement(91,2), ReagentElement(92,3)}),
        // ItemToCraft(33, std::vector<ReagentElement> {ReagentElement(91,2), ReagentElement(92,3)}),

    } {}

void Workshop::showItemsToCraft() {
    int choise {1};

    while(choise != MenuChoise::exit) {
        checkInputWithMessage();

        //Show list of items to craft
        cout << "\nВы можете создать: \n\n";
        for(int i{0}; i < m_instance->m_items.size(); ++i){
            if(m_instance->m_items.at(i).m_itemId == LocationConstants::firstHelmIdToCraft)
                cout << "Шлемы:\n";
            else if(m_instance->m_items.at(i).m_itemId == LocationConstants::firstChestIdToCraft)
                cout << "\nБроня на тело:\n";
            else if(m_instance->m_items.at(i).m_itemId == LocationConstants::firstWeaponIdToCraft)
                cout << "\nОружия:\n";

            cout << i+1 << ". " << AllItemsDB::getItemByID(m_instance->m_items.at(i).m_itemId)->getName()
                << " - " << getAvailableNumber(i) << ".\n";
        }
        cout <<"\n" << MenuChoise::exit << ". Выход" << "\nВаш выбор: ";

        choise = getChoise();

        // number within range
        if(choise > 0 && choise <= m_instance->m_items.size())
            //-1 because real position n-1
            craftMenu(choise-1);
        //Exit
        else if(choise == MenuChoise::exit)
            return;
        //Bad input
        else
            badInputState();
    }
}

void Workshop::craftMenu(const int s_position) {
    int choise {1};

    while(choise != MenuChoise::exit) {
        checkInputWithMessage();

        //Show information
        AllItemsDB::getItemByID(m_instance->m_items.at(s_position).m_itemId)->showDescription();
        cout << "\n\nРеагенты:\n";
        showReagents(s_position);

        int availableNumber {getAvailableNumber(s_position)};
        cout << "\nВы можете создать: " << availableNumber
            << "\nСколько создать (" << MenuChoise::exit << "-выход): ";

        choise = getChoise();

        // number within range
        if(choise > 0 && choise <= availableNumber){
            Bag::putToBag(m_instance->m_items.at(s_position).m_itemId, choise);

            for(int i {0}; i < m_instance->m_items.at(s_position).m_reagents.size(); ++i) {
                int id {m_instance->m_items.at(s_position).m_reagents.at(i).getId()};
                int count {m_instance->m_items.at(s_position).m_reagents.at(i).getCount()};

                Bag::takeFromBag(id, count * choise);
            }
            return;
        } 
        //Exit
        else if (choise == MenuChoise::exit)
            return;
        //Bad Input
        else
            badInputState();
    }
}

int Workshop::getAvailableNumber(const int s_position) {
    int availableNumber;
    for(int i{0}; i < m_instance->m_items.at(s_position).m_reagents.size(); ++i) {
        int nededCount {m_instance->m_items.at(s_position).m_reagents.at(i).getCount()};
        int existCount {Bag::getCounterById(m_instance->m_items.at(s_position).m_reagents.at(i).getId())};

        int tempAvailableNumber = existCount / nededCount;

        if(tempAvailableNumber == 0)
            return tempAvailableNumber;
        if(tempAvailableNumber < availableNumber || i == 1)
            availableNumber = tempAvailableNumber;
    }
    return availableNumber;
}

void Workshop::showReagents(const int s_position) {
    for(int i {0}; i < m_instance->m_items.at(s_position).m_reagents.size(); ++i){
        cout << AllItemsDB::getItemByID(m_instance->m_items.at(s_position).m_reagents.at(i).getId())->getName()
            << " " << m_instance->m_items.at(s_position).m_reagents.at(i).getCount() << ".\n";
    }
}