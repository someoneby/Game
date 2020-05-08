#ifndef GAME_CHAR_CONSTANTS_H
#define GAME_CHAR_CONSTANTS_H

#include "Parameters/Parameters.h"

namespace CharConstants {
    const Parameters PLAYER(500000, 1.0, 0.1, 50, 0.2, "Player");
    const int MAX_ENERGY {200};
    const int ENERGY_REGEN_TIME {3600};
};


#endif //GAME_CHAR_CONSTANTS_H