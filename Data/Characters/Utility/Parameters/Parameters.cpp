#include "../Parameters/Parameters.h"

Parameters::Parameters(const int s_hp, const float s_armor, const float s_avoidChance, const int s_damage,
    const float s_critChance, const string& s_name) : m_hp{s_hp}, m_armor{s_armor},
    m_avoidChance{s_avoidChance}, m_damage{s_damage}, m_critChance{s_critChance}, m_name{s_name} 
{}