#include "Helm.h"

Helm::Helm (int armor, float avoidChanse, int hp) : Armor(armor, avoidChanse, hp) {};

int Helm::getHP(){
    return m_hp;
}