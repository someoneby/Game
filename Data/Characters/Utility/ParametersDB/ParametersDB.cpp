#include "ParametersDB.h"
#include "vector"
using std::vector;

ParametersDB* ParametersDB::m_instance =  new ParametersDB();

ParametersDB::ParametersDB() :
    m_mobs {
        Parameters(200, 1.0, 0.1, 50, 0.2, "Тимати"),
        Parameters(220, 2.0, 0.1, 55, 0.2, "Егор Крид"),
        Parameters(250, 2.0, 0.2, 60, 0.2, "Киркоров"),
    }
{}

Parameters& ParametersDB::getParam(const int s_mobId) {
    return m_instance->m_mobs.at(s_mobId);
}

int ParametersDB::getMobsNumber() {
    return m_instance->m_mobs.size();
}
