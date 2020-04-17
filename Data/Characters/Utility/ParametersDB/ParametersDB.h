#ifndef GAME_PARAMETERSDB_H
#define GAME_PARAMETERSDB_H

#include "../Parameters/Parameters.h"
#include<vector>
using std::vector;

class ParametersDB {
        vector<Parameters> m_units;
        static ParametersDB* m_instance;
    public:
        static Parameters& getParam(const int);
        ParametersDB();
};

#endif //GAME_PARAMETERSDB_H