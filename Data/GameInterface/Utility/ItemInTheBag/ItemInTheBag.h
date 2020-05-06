#ifndef GAME_ITEMINTHEBAG_H
#define GAME_ITEMINTHEBAG_H

class ItemInTheBag {
        int m_id;
        int m_count;
    public:
        ItemInTheBag(int itemId, int number);
        int getId() { return m_id; };
        int getCount() { return m_count; };
        void changeCount(int number) { m_count += number; };
};


#endif //GAME_ITEMINTHEBAG_H