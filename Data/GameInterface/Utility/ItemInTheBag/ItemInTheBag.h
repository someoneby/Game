#ifndef GAME_ITEMINTHEBAG_H
#define GAME_ITEMINTHEBAG_H

class ItemInTheBag {
        int m_id;
        int m_count;
    public:
        ItemInTheBag(int itemId, int number);
        int getId();
        int getCount();
        void changeCount(int number);
};


#endif //GAME_ITEMINTHEBAG_H