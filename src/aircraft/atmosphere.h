#ifndef __ATMOSPHERE_H__
#define __ATMOSPHERE_H__

#include <math.h>

#define REFP 1 //Reference pressure
#define REFT 20 //Reference temp
#define REFH 0 //Reference height
#define REFD 1.225 //Reference density
#define tlps 2 //Lapse rate

#define gasConst 8.3144598 //Gas const
#define grvAccel 9.80665 //Gravitational acceleration
#define mlrMass 0.0289644 //Earth's molar mass

float calculateAtmospherePressure(float altitude) {
    float equationBase = REFP * ((REFT + tlps * (altitude - REFH)) / REFT);
    float equationPowr = (- grvAccel * mlrMass) / (gasConst * tlps);


    return pow(equationBase, equationPowr);
}

float calculateAtmosphereDensity(float altitude) {
    float equationBase = REFD * (REFT / (REFT + tlps * (altitude - REFH)));
    float equationPowr = 1 + ((grvAccel * mlrMass) / (gasConst * tlps));

    return pow(equationBase, equationPowr);
}

#endif