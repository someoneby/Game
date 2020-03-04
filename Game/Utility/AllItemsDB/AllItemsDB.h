#ifndef GAME_ALLITEMS_H
#define GAME_ALLITEMS_H

#include "../../Items/Item/Item.h"
#include "vector"
class AllItemsDB {
    private:
        AllItemsDB();
        AllItemsDB(const AllItemsDB &) = delete;
        AllItemsDB & operator = (AllItemsDB &) = delete;
        static AllItemsDB * m_instance;
        
        static std::vector<Item *> m_allItemsDB;
    public:
        static Item * getItemByID(int);
        
};


#endif