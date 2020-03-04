#include "AllItemsDB.h"
#include "vector"
#include "../../Items/Helm/Helm.h"


std::vector<Item *> AllItemsDB::m_allItemsDB {  
    new Helm(0, "Кастрюля дырявая", 5, 0, 10),
    new Helm(1, "Кастрюля картавая", 7, 0, 16),
    new Helm(2, "Ведро жестяное", 10, 0, 20),
    new Helm(3, "Каска деда-электрика", 15, 0, 25)
};

Item * AllItemsDB::getItemByID(int s_id) {
    return m_allItemsDB.at(s_id);
}