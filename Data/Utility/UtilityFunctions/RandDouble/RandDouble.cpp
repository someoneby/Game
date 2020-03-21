#include "RandDouble.h"
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/variate_generator.hpp>

typedef boost::mt19937 BaseGenerator;
typedef boost::uniform_real<double> Distribution;
typedef boost::variate_generator<BaseGenerator, Distribution> Generator;

//Ничего не понимаю, но работает
double randDouble () {
    static BaseGenerator base;
    static Distribution dist;
    static Generator rng(base, dist);

    return rng();
};