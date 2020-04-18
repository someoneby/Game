#include "Depths.h"
#include "../../Characters/Player/Player.h"
#include "../../Characters/MobFactory/MobFactory.h"
#include "../../GameInterface/Bag/Bag.h"
#include "../../GameInterface/EquipedItems/EquipedItems.h"
#include "../Utility/LocationConstants.h"
#include "../../Utility/UtilityFunctions/GetChoise/GetChoise.h"
#include "../../Utility/UtilityFunctions/CheckInputWithMessage/CheckInputWithMessage.h"
#include "../../Utility/UtilityFunctions/BadInputState/BadInputState.h"
using std::cout;


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
            << "\n\n 0. Выйти из шахты"
            << "\nВаш выбор: ";

        choise = getChoise();

        switch (choise) {
            case LocationConstants::GO_DEEPER : {
                Player::spendEnergy(5);
                int result = goDeeper(level);
                
                if(result) {
                    level++;
                }
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

bool Depths::goDeeper(const int s_level) {
    int choise{1};
    Mob* mob {MobFactory::getMob(s_level)};

    while(choise) {
        checkInputWithMessage();
        
        cout << "Ваш путь преградил " << mob->getName()
            << "\n Хп: " << mob->getHP()
            << "\n Броня: " << mob->getArmor()
            << "\n Урон: " << mob->getDamage()
            << "\n\n 1. Напасть"
            << "\n 2. Сумка"
            << "\n 3. Меню персонажа"
            << "\n\n0. Выйти из шахты"
            << "\nВаш выбор: ";

        choise = getChoise();

        switch (choise)
        {
        case LocationConstants::FIGHT : {
            bool win {Player::fight(mob)};

            // Will change to shared_ptr
            delete mob; 

            cout << "\n\nЛюбой ввод для продолжения: ";
            getChoise();

            if(win){
                return true;
            }
            else {
                return false;
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