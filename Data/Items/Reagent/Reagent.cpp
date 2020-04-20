#include "Reagent.h"

Reagent::Reagent(int s_id, std::string s_name, std::string s_description, int s_prise) {
            m_id = s_id;
            m_name = s_name;
            m_description = s_description;
            m_prise = s_prise;
}

/*
    Show description of the item.
*/
void Reagent::showDescription() const {
    std::cout <<m_name << "\n\n" << m_description;
}