
#ifndef SDAT_TEMPERATURESENSOR_H
#define SDAT_TEMPERATURESENSOR_H


class TemperatureSensor{
public:
    TemperatureSensor();
    void generateData();
    double getData() const;

private:
    double currentTemp;
};


#endif //SDAT_TEMPERATURESENSOR_H
