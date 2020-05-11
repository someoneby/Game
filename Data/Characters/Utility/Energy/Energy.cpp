#include "Energy.h"
#include "../CharConstants.h"
#include <chrono>


Energy::Energy(const float s_energy) noexcept : m_energy{s_energy} {
}


/*
    This function recounts energy cose it has regeneration, cast energy to int and return it.
*/
int Energy::getEnergy() noexcept {
    recount();
    return m_energy;
}


/*
    Regeneration of energy.
*/
void Energy::recount() noexcept {
    static auto lastCheckTime {std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())};

    auto delayTime {std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) - lastCheckTime};
    lastCheckTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    m_energy += ((float)delayTime / CharConstants::ENERGY_REGEN_TIME) * CharConstants::MAX_ENERGY;

    if(m_energy > CharConstants::MAX_ENERGY)
        m_energy = CharConstants::MAX_ENERGY;
}