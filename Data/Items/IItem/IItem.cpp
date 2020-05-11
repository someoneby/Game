#include "IItem.h"

IItem::IItem(const int s_id, const std::string s_name, const int s_prise, const std::string s_description) noexcept :
    m_id{s_id}, m_name{s_name}, m_prise{s_prise}, m_description{s_description} {
}


IItem::~IItem() {}