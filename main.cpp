#include <iostream>
#include "Sensor.h"
#include "Missile_Controls.h"
using namespace std;

int main() {
    Target_Coordinates destination(48.8566, 2.3522);

    MissileControls controls = MissileControls(48.8074, 2.3522);
    controls.launchMissile();
    Motion motion(controls, destination);
    motion.setVelocity(900.00);

    motion.missileInMotion();

    return 0;
}
