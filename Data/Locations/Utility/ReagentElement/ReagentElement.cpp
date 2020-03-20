#include "ReagentElement.h"

ReagentElement::ReagentElement(int s_id, int s_count): m_id{s_id}, m_count{s_count} {}

int ReagentElement::getCount(){
    return m_count;
}

int ReagentElement::getId(){
    return m_id;
}