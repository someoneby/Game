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
        Vendor() noexcept;
        static void showMenuToBuy() noexcept;
        static void showMenuToSell() noexcept;
        static void showDescriptionToBuy(const int id) noexcept;
        static void showDescriptionToSell(const int position) noexcept;
    public:
        static void showMenu() noexcept;
};

#endif //GAME_VENDOR_H