#ifndef GAME_IITEM_H
#define GAME_IITEM_H

#include <iostream>

class IItem {
    protected:
        int m_id;
        std::string m_name;
        int m_prise;
        std::string m_description;
    public:
        IItem(const int id, const std::string name, const int prise, const std::string description);
        virtual void showDescription() const = 0;
        virtual ~IItem() = 0;

        int getId() const { return m_id; };
        std::string getName() const { return m_name; };
        int getPrise() const { return m_prise; };
};

#endif