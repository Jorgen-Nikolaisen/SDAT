
#ifndef SDAT_MISSILE_CONTROLS_H
#define SDAT_MISSILE_CONTROLS_H


class MissileControls {
public:
    MissileControls(double longitude, double latitude);
    void launchMissile();
    bool missileInMotion();
    double getStartLatitude();
    double getStartLongitude();
private:
    bool launch;
    double startLatitude, startLongitude;

};


#endif //SDAT_MISSILE_CONTROLS_H
