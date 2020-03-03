#include "Equipment.h"

float Equipment::getIlvl() {
    return m_ilvl;
}

Equipment::Equipment(int s_id, std::string s_name) : Item(s_id, s_name) {};
