#include "../Parameters/Parameters.h"

Parameters::Parameters(int s_hp, float s_armor, float s_avoidChance, int s_damage, float s_critChance,
    string s_name) : m_hp{s_hp}, m_armor{s_armor}, m_avoidChance{s_avoidChance}, m_damage{s_damage},
    m_critChance{s_critChance}, m_name{s_name} {}