#include "ParametersDB.h"
#include "vector"
using std::vector;

ParametersDB* ParametersDB::m_instance =  new ParametersDB();

ParametersDB::ParametersDB() :
    m_units {
        //Mobs
        Parameters(200, 1.0, 0.1, 50, 0.2, "Тимати"),
        Parameters(220, 2.0, 0.1, 55, 0.2, "Егор Крид"),
        Parameters(250, 2.0, 0.2, 60, 0.2, "Киркоров"),
    }{}

Parameters& ParametersDB::getParam(const int s_unitIndex) {
    return m_instance->m_units.at(s_unitIndex);
}
