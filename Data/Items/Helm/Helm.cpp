#include "Helm.h"

Helm::Helm (int s_id, std::string s_name, int s_armor, float s_avoidChanse, int s_hp) : Armor(s_id, s_name, s_armor, s_avoidChanse, s_hp) {};

int Helm::getHP(){
    return m_hp;
}

// void Helm::equip(int id) {
//     std::cout << "\nEQUIP\n" ;
// }