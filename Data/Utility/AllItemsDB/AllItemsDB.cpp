#include "AllItemsDB.h"
#include "vector"
#include "../../Items/Helm/Helm.h"


std::vector<Item *> AllItemsDB::m_allItemsDB {  
    new Helm(1, "Кастрюля дырявая", 5, 0, 10),
    new Helm(2, "Кастрюля картавая", 7, 0, 16),
    new Helm(3, "Ведро жестяное", 10, 0, 20),
    new Helm(4, "Каска деда-электрика", 15, 0, 25)
};

Item * AllItemsDB::getItemByID(int s_id) {
    for(int i{0}; i < m_allItemsDB.size(); ++i){
        if(m_allItemsDB.at(i)->getId() == s_id)
            return m_allItemsDB.at(i);
    }
}