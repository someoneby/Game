#include "AllItems.h"
#include "vector"
#include "../Helm/Helm.h"

std::vector<Item *> getAllItems() {
    static std::vector<Item *> items;

    if(items.size != 0)
        return items;
        
    items.push_back(new Helm(0, "Кастрюля дырявая", 5, 0, 10));
    items.push_back(new Helm(1, "Кастрюля картавая", 7, 0, 16));
    items.push_back(new Helm(2, "Ведро жестяное", 10, 0, 20));
    items.push_back(new Helm(3, "Каска деда-электрика", 15, 0, 25));

    return items;
}