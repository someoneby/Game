#include "Helm.h"

Helm::Helm (int s_id, std::string s_name, int s_armor, float s_avoidChanse, int s_hp, int s_prise, std::string s_description) :
         Armor(s_id, s_name, s_description, s_armor, s_avoidChanse, s_hp, s_prise) {};
