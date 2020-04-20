#include "IItem.h"

/*
    Return id of the item.
*/
int IItem::getId() const {
    return m_id;
}

/*
    Return name of the item.
*/
std::string IItem::getName() const {
    return m_name;
}

/*
    Return prise of the item.
*/
int IItem::getPrise() const {
    return m_prise;
}

IItem::~IItem() {}