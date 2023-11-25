#include "TemperatureSensor.h"
#include <iostream>
#include <random>


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
