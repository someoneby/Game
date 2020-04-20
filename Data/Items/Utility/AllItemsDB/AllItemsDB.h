#ifndef GAME_ALLITEMS_H
#define GAME_ALLITEMS_H

#include "../../IItem/IItem.h"
#include "vector"

class AllItemsDB {
    private:
        AllItemsDB();
        static AllItemsDB * m_instance;
        std::vector<IItem*> m_allItemsDB;
    public:
        static IItem * getItemByID(int);
};


#endif