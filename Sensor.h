
#ifndef SDAT_SENSOR_H
#define SDAT_SENSOR_H
#include "Missile_Controls.h"

class Target_Coordinates{
public:
    Target_Coordinates(double latitude, double longitude);
    double getCurrentDistance(double missileLatitude, double missileLongitude);
    double getLat();
    double getLong();

private:
    double latitude, longitude;
};

class Motion {
private:
    double missileVelocity, missileBearing;
    MissileControls isFlying;
    Target_Coordinates position;
    double lat1, lat2, lon1, lon2;


public:
    Motion(MissileControls isFlying, Target_Coordinates position);

    void setVelocity(double missileVelocity);
    double setBearing(double lat1, double lon1, double lat2, double lon2);
    void missileInMotion();
};

#endif //SDAT_SENSOR_H
