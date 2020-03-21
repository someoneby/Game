#ifndef GAME_ITEMINTHEBAG_H
#define GAME_ITEMINTHEBAG_H

class ItemInTheBag {
        int m_id;
        int m_count;
    public:
        ItemInTheBag(int, int);
        int getId();
        int getCount();
        void changeCount(int);
};


#endif //GAME_ITEMINTHEBAG_H