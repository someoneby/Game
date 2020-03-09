#ifndef GAME_VENDOR_H
#define GAME_VENDOR_H

#include "vector"

class Vendor {
    private:
        static std::vector<int> itemsIdToBuy;
    public:
        static void showMenuOfVendor();
        static void showMenuToBuy();
        static void showMenuToSell();
};

#endif //GAME_VENDOR_H