#include "Helm.h"

Helm::Helm (const int s_id, const std::string s_name, const int s_armor, const float s_avoidChanse,
    const int s_hp, const int s_prise, const std::string s_description) noexcept :
         Armor(s_id, s_name, s_prise, s_description, s_hp, s_armor, s_avoidChanse) {
};
