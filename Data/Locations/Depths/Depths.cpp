#include "Depths.h"
#include "../../Characters/Player/Player.h"
#include "../../Characters/MobFactory/MobFactory.h"
#include "../../GameInterface/Bag/Bag.h"
#include "../../GameInterface/EquipedItems/EquipedItems.h"
#include "../Utility/LocationConstants.h"
#include "../../Utility/UtilityFunctions/GetChoise/GetChoise.h"
#include "../../Utility/UtilityFunctions/CheckInputWithMessage/CheckInputWithMessage.h"
#include "../../Utility/UtilityFunctions/BadInputState/BadInputState.h"
#include "../Utility/TakeLoot/TakeLoot.h"
using std::cout;

/*
    Main menu of depths, it shows level and energy. 
*/
void Depths::mainMenu() {
    int choise{1};
    int level{0};

    while(choise) {
        checkInputWithMessage();

        cout << "Шахта"
            << "\n Глубина: " << level
            << "\n Энергия: " << Player::getEnergy()
            << "\n Хп: " << Player::getInstance()->getHP()
            << "\n\n 1. Спускаться дальше (-5 энергии)"
            << "\n 2. Сумка"
            << "\n 3. Меню персонажа"
            << "\n\n0. Выйти из шахты"
            << "\nВаш выбор: ";

        choise = getChoise();

        switch (choise) {
            case LocationConstants::GO_DEEPER : {
                Player::spendEnergy(5);
                int result = goDeeper(level);
                
                cout << "\n\nЛюбой ввод для продолжения: ";
                getChoise();
                
                // Win
                if(result) {
                    level++;
                }
                // Lose or exit
                else {
                    return;
                }
                break;
            }
            case LocationConstants::BAG : {
                Bag::showMenu();
                break;
            }
            case LocationConstants::PERSON_MENU : {
                EquipedItems::showMenu();
                break;
            }
            case LocationConstants::EXIT : {
                return;
            }
            default : {
                badInputState();
            }
        }
    }
}

/*
    Go next level of depth and meet the mob.
*/
bool Depths::goDeeper(const int s_level) {
    int choise{1};
    Mob* mob {MobFactory::getMob(s_level)};

    while(choise) {
        checkInputWithMessage();
        
        cout << "Ваш путь преградил " << mob->getName() << ":"
            << "\nХп: " << mob->getHP()
            << "\nБроня: " << mob->getArmor()
            << "\nУрон: " << mob->getDamage()
            << "\n\n 1. Напасть"
            << "\n 2. Сумка"
            << "\n 3. Меню персонажа"
            << "\n\n0. Выйти из шахты"
            << "\nВаш выбор: ";

        choise = getChoise();

        switch (choise) {
            case LocationConstants::FIGHT : {
                bool win {Player::fight(mob)};

                // Will change to unique_ptr
                delete mob; 

                // cout << "\n\nЛюбой ввод для продолжения: ";
                // getChoise();

                if(win){
                    takeLoot(s_level);
                    return LocationConstants::WIN;
                }
                else {
                    return LocationConstants::DIED;
                }
            }
            case LocationConstants::BAG : {
                Bag::showMenu();
                break;
            }
            case LocationConstants::PERSON_MENU : {
                EquipedItems::showMenu();
                break;
            }
            case LocationConstants::EXIT : {
                return LocationConstants::EXIT;
            }
            default:
                badInputState();
                break;
        }
    }
}