#ifndef __AIRCRAFT_H__
#define __AIRCRAFT_H__

#define gravity 9.80665

#include <math.h>
#include "./atmosphere.h"
#include "../lib/graph.h"
#include "../lib/appendString.h"



struct AircraftControlSurfaceData {
    //Here because some aircraft have L and R rudders but no middle one
    //Most also have a middle one and no L and R rudders
    int doesExist;

    char* commandName;

    double deflectionLimitDegrees;
    double rateLimitPerSecDegrees;
    float timeLagConstant;

    int canGoNegative;
    int canGoPositive;
};


struct Aircraft {
    char* aircraftName;

    struct GraphData lift;
    struct GraphData drag;
    struct GraphData torque;

    struct AircraftControlSurfaceData leftElevator;
    struct AircraftControlSurfaceData leftAileron;
    struct AircraftControlSurfaceData leftRudder;

    struct AircraftControlSurfaceData rightElevator;
    struct AircraftControlSurfaceData rightAileron;
    struct AircraftControlSurfaceData rightRudder;

    struct AircraftControlSurfaceData middleRudder;

    int aircraftWeight;


    float aircraftVelocity[3][2]; //Velocity vectors of the aircraft
    float aircraftPosition[3]; //Position of the aircraft
    float aircraftRotation[3]; //Rotation of the aircraft



    float aircraftElevLift; //Used for pitch
    float aircraftLWingLift; //Used for roll
    float aircraftRWingLift; //Used for roll
    float aircraftTailLift[2]; //Used for yaw


    double airfoil; //Airfoil thickness-to-cord percentage
    double bank; //Angle of the turn used for G calculations
    double span; //Wingspan of the aircraft
    double fuelCap; //Interal fuel capacity in liters


    //First index contains if it has it, second is if its enabled
    int takeoffFlaps[2];
    int landingFlaps[2];
    int combatFlaps[2];
    int airbrakes[2];
    int arrestor[2];
    int chute[2];

    double wingspan; //Wingspan in meters squared
    double wingarea; //Area of the wing
    double aspectRa; //Aspect ratio of the aircraft
    double meanChord; //Mean aerodynamic chord

    double rollMomentOfInertia;
    double pitchMomentOfInertia;
    double yawMomentOfInertia;

    double productMomentOfInertiaX;
    double productMomentOfInertiaY;
    double productMomentOfInertiaZ;


    float (*getAircraftVelocity)(struct Aircraft *);

    //Check if a aircraft has it
    int (*doesHaveTakeOffFlaps)(struct Aircraft *);
    int (*doesHaveLandingFlaps)(struct Aircraft *);
    int (*doesHaveCombatFlaps)(struct Aircraft *);
    int (*doesHaveAirbrakes)(struct Aircraft *);
    int (*doesHaveArrestor)(struct Aircraft *);
    int (*doesHaveChute)(struct Aircraft *);

    //Check if part of a aircraft is enabled
    int (*isTakeOffFlapsEnabled)(struct Aircraft *);
    int (*isLandingFlapsEnabled)(struct Aircraft *);
    int (*isCombatFlapsEnabled)(struct Aircraft *);
    int (*isAirbrakesEnabled)(struct Aircraft *);
    int (*isChuteEnabled)(struct Aircraft *);

    float (*updateLiftCoefficient)(struct Aircraft *);
    float (*updateDragCoefficient)(struct Aircraft *);
    float (*updateTorqueCoefficient)(struct Aircraft *);

    void (*updateAircraftLDT)(struct Aircraft *); //Update aircraft lift, drag and torque
    void (*updateAircraftVel)(struct Aircraft *); //Update aircraft velocity vectors
};









float getAircraftVelocity(struct Aircraft *a) { //Use the pythogrean theorem to get velocity
    float xVelocity = pow(a->aircraftVelocity[0][0], 2); //Square of X velocity vector
    float yVelocity = pow(a->aircraftVelocity[1][0], 2); //Square of Y velocity vector
    float zVelocity = pow(a->aircraftVelocity[2][0], 2); //Square of Z velocity vector

    return sqrt(xVelocity + yVelocity + zVelocity); //Sqrt everything to get the velocity
}


//Shitty functions that are needed but I hate
int doesHaveTakeOffFlaps(struct Aircraft *a) { return a->takeoffFlaps[0]; }
int doesHaveLandingFlaps(struct Aircraft *a) { return a->landingFlaps[0]; }
int doeshaveCombatFlaps(struct Aircraft *a) { return a->combatFlaps[0]; }
int doesHaveAirbrakes(struct Aircraft *a) { return a->airbrakes[0]; }
int doesHaveArrestor(struct Aircraft *a) { return a->arrestor[0]; }
int doeshaveChute(struct Aircraft *a) { return a->chute[0]; }

int isTakeOffFlapsEnabled(struct Aircraft *a) { return a->takeoffFlaps[1]; }
int isLandingFlapsEnabled(struct Aircraft *a) { return a->landingFlaps[1]; }
int isCombatFlapsEnabled(struct Aircraft *a) { return a->combatFlaps[1]; }
int isAirbrakesEnabled(struct Aircraft *a) { return a->airbrakes[1]; }
int isChuteEnabled(struct Aircraft *a) { return a->chute[1]; }



#endif
