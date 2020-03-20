#include "Reagent.h"

Reagent::Reagent(int s_id, std::string s_name, std::string s_description, int s_prise):
    Item(s_id, s_name, s_description, s_prise) {}

void Reagent::showDescription() {
    std::cout <<m_name << "\n\n" << m_description;
}