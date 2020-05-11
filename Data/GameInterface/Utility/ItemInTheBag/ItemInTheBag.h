#ifndef GAME_ITEMINTHEBAG_H
#define GAME_ITEMINTHEBAG_H

class ItemInTheBag {
        int m_id;
        int m_count;
    public:
        ItemInTheBag(int itemId, int number) noexcept;
        int getId() noexcept { return m_id; };
        int getCount() noexcept { return m_count; };
        void changeCount(int number) noexcept { m_count += number; };
};


#endif //GAME_ITEMINTHEBAG_H