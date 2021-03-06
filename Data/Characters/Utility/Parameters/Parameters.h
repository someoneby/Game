#ifndef GAME_PARAMETERS_H
#define GAME_PARAMETERS_H

#include <iostream>
using std::string;

struct Parameters {
    const int m_hp;
    const float m_armor;
    const float m_avoidChance;
    const int m_damage;
    const float m_critChance; 
    const string m_name;
    Parameters(const int hp, const float armor, const float avoidChance, const int damage,
        const float critChance, const string& name);
};

#endif //GAME_PARAMETERS_H
