#include "ReagentElement.h"

ReagentElement::ReagentElement(const int s_id, const int s_count): m_id{s_id}, m_count{s_count} {}

int ReagentElement::getCount(){
    return m_count;
}

int ReagentElement::getId(){
    return m_id;
}