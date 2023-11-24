//
// Created by PC on 11/23/2023.
//

#include <iostream>
#include "Missile_Controls.h"


MissileControls::MissileControls(double startLatitude, double startLongitude) : startLatitude(startLatitude),
startLongitude(startLongitude), launch(false){}

    void MissileControls::launchMissile(){
        launch = true;
    }

    bool MissileControls::missileInMotion(){
        return launch;
    }

    double MissileControls::getStartLatitude(){
        return this-> startLatitude;
    }

    double MissileControls::getStartLongitude(){
        return this-> startLongitude;
    }


