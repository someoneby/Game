#include "Reagent.h"

Reagent::Reagent(const int s_id, const std::string s_name, const std::string s_description, const int s_prise) noexcept :
    IItem(s_id, s_name, s_prise, s_description) {
}
