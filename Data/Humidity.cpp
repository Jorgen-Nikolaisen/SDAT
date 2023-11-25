#include "Humidity.h"
#include <iostream>
#include <random>

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