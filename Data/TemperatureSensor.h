
#ifndef SDAT_TEMPERATURESENSOR_H
#define SDAT_TEMPERATURESENSOR_H


class TemperatureSensor{
public:
    TemperatureSensor();
    double getTemperature(double latitude, double longitude);

private:
    double currentTemp;
};


#endif //SDAT_TEMPERATURESENSOR_H
