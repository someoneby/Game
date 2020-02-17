#include "Player.h"
#include "../../Utility/Constans/Parameters.h"


Player::Player() : Unit(Parameters::playerArmor, Parameters::playerHP, Parameters::playerDamage,
        Parameters::playerAvoidChance){ }

void Player::fight(IUnit * mob) {

    while (m_hp != 0 && mob->getHP() != 0){
        this->hit(mob);
        mob->hit(this);
    }
}
