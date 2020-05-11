#ifndef GAME_ENERGY_H
#define GAME_ENERGY_H


class Energy {
        friend class Player;
        float m_energy;
        
        void recount() noexcept;
    public:
        Energy(const float energy) noexcept;
        void spendEnergy(const int energy) noexcept { m_energy -= energy; };
        int getEnergy() noexcept;
};

#endif //GAME_ENERGY_H