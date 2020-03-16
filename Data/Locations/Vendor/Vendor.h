#ifndef GAME_VENDOR_H
#define GAME_VENDOR_H

#include "vector"

class Vendor {
    private:
        static std::vector<int> m_itemsIdToBuy;
    public:
        static void showMenuOfVendor();
        static void showMenuToBuy();
        static void showMenuToSell();

        static void showDescriptionToBuy(int);
        static void showDescriptionToSell(int);
};

#endif //GAME_VENDOR_H