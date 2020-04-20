#ifndef GAME_IITEM_H
#define GAME_IITEM_H

#include <iostream>

class IItem {
    protected:
        std::string m_name;
        int m_id;
        int m_prise;
        std::string m_description;
    public:
        virtual void showDescription() const = 0;
        virtual int getId() const;
        virtual std::string getName() const;
        virtual int getPrise() const;
        virtual ~IItem() = 0;
};

#endif