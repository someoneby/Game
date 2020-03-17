#ifndef GAME_VENDOR_H
#define GAME_VENDOR_H

#include "vector"

class Vendor {
    private:
        static std::vector<int> m_itemsIdToBuy;
        
        static void showMenuToBuy();
        static void showMenuToSell();
        static void showDescriptionToBuy(int);
        static void showDescriptionToSell(int);
    public:
        static void showMenuOfVendor();

};

#endif //GAME_VENDOR_H