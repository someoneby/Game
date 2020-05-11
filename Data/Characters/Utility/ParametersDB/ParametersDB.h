#ifndef GAME_PARAMETERSDB_H
#define GAME_PARAMETERSDB_H

#include "../Parameters/Parameters.h"
#include<vector>
using std::vector;

class ParametersDB {
        vector<Parameters> m_mobs;
        static ParametersDB* m_instance;
    public:
        static Parameters& getParam(const int mobId) noexcept { return m_instance->m_mobs.at(mobId); };
        static int getMobsNumber() noexcept { return m_instance->m_mobs.size(); };
        ParametersDB() noexcept;
};

#endif //GAME_PARAMETERSDB_H