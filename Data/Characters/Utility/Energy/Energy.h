#ifndef GAME_ENERGY_H
#define GAME_ENERGY_H


class Energy {
        friend class Player;
        float m_energy;
        
        void recount();
    public:
        Energy(const float energy);
        void spendEnergy(const int energy) { m_energy -= energy; };
        int getEnergy();
};

#endif //GAME_ENERGY_H