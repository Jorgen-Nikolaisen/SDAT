#include <iostream>
#include <vector>
#include <random>
#include "Missile_Controls.h"
#include <thread>
#include "Sensor.h"

TemperatureSensor::TemperatureSensor() : currentTemp(0.0){}

void TemperatureSensor::generateData(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-20.0, 40.0);

    currentTemp = dis(gen);
}

    double TemperatureSensor::getData() const{
        return currentTemp;
    }

Humidity::Humidity() : currentHumidity(0){}

void Humidity::generateData(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 100);

    currentHumidity = dis(gen);
    }

int Humidity::getData() const{
    return currentHumidity;
}



Target_Coordinates::Target_Coordinates(double latitude, double longitude) {
        this -> latitude = latitude * M_PI / 180.0;  //Convert to radians
        this -> longitude = longitude * M_PI / 180.0;
    }

    double Target_Coordinates::getCurrentDistance(double missileLatitude, double missileLongitude){
        missileLatitude *= M_PI / 180.0; //Convert to radians
        missileLongitude *= M_PI / 180.0;

        double deltaLat = missileLatitude - this->latitude;
        double deltaLong = missileLongitude - this->longitude;

        //Implementing Haversine formula for getting distance between missile and destination
        double a = pow(sin(deltaLat/2), 2) + cos(this->latitude) * cos(missileLatitude)
                * pow(sin(deltaLong/2),2);
        double c = 2 * atan2(sqrt(a), sqrt(1-a));

        const double EARTH_RADIUS = 6371.0; // Earth's radius in KM
        return EARTH_RADIUS * c;
    }

    double Target_Coordinates::getLat(){
        return this->latitude;
    }

    double Target_Coordinates::getLong(){
        return this->longitude;
    }




Motion::Motion(MissileControls isFlying, Target_Coordinates position) : isFlying(isFlying), position(position){}

    void Motion::setVelocity(double newMissileVelocity){
        this->missileVelocity = newMissileVelocity;
    }

    double Motion::setBearing(double lat1, double lon1, double lat2, double lon2) {
    this -> lat1 = lat1 * M_PI / 180.0; // Convert to radians
    this-> lon1 = lon1* M_PI / 180.0;
    this-> lat2 = lat2 * M_PI / 180.0;
    this-> lon2 = lon2 * M_PI / 180.0;

    double deltaLon = lon2 - lon1;
    double x = sin(deltaLon) * cos(lat2);
    double y = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(deltaLon);
    double initialBearing = atan2(x, y);
    initialBearing = fmod((initialBearing * 180.0 / M_PI + 360.0), 360.0); // Convert to degrees and normalize
    return initialBearing;
}

void Motion::missileInMotion() {
    double latRad = isFlying.getStartLatitude() * M_PI / 180.0;
    double lonRad = isFlying.getStartLongitude() * M_PI / 180.0;
    const double EARTH_RADIUS = 6371.0;

    while (isFlying.missileInMotion()) {
        double targetLatRad = position.getLat() * M_PI / 180.0;
        double targetLonRad = position.getLong() * M_PI / 180.0;

        // Recalculate bearing at each step
        double y = sin(targetLonRad - lonRad) * cos(targetLatRad);
        double x = cos(latRad) * sin(targetLatRad) - sin(latRad) * cos(targetLatRad) * cos(targetLonRad - lonRad);
        double radBearing = atan2(y, x);

        // Calculate the distance traveled in 1 second
        double distance = missileVelocity * (1.0 / 3600.0);

        // Update position
        latRad -= distance * cos(radBearing) / EARTH_RADIUS;
        lonRad -= distance * sin(radBearing) / (EARTH_RADIUS * cos(latRad));

        // Convert back to degrees
        double updatedLat = latRad * 180.0 / M_PI;
        double updatedLon = lonRad * 180.0 / M_PI;

        double currentDistance = position.getCurrentDistance(updatedLat, updatedLon);
        std::cout << currentDistance << " km to target" << std::endl;

        if (currentDistance <= missileVelocity / 1000) {
            std::cout << "Impact!" << std::endl;
            break;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}




