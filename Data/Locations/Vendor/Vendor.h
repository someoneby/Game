#ifndef GAME_VENDOR_H
#define GAME_VENDOR_H

#include "vector"

/* 
    This class is location where you can buy or sale goods
*/
class Vendor {
    private:
        std::vector<int> m_itemsIdToBuy;
        static Vendor* m_instance;
        Vendor();
        static void showMenuToBuy();
        static void showMenuToSell();
        static void showDescriptionToBuy(const int id);
        static void showDescriptionToSell(const int position);
    public:
        static void showMenu();
};

#endif //GAME_VENDOR_H