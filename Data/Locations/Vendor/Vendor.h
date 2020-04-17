#ifndef GAME_VENDOR_H
#define GAME_VENDOR_H

/* 
    This class is location where you can buy or sale goods
*/

#include "vector"

class Vendor {
    private:
        std::vector<int> m_itemsIdToBuy;
        static Vendor* m_instance;
        Vendor();
        static void showMenuToBuy();
        static void showMenuToSell();
        static void showDescriptionToBuy(const int);
        static void showDescriptionToSell(const int);
    public:
        static void showMenu();
};

#endif //GAME_VENDOR_H