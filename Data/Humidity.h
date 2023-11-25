
#ifndef SDAT_HUMIDITY_H
#define SDAT_HUMIDITY_H

class Humidity{
public:
    Humidity();
    void generateData();
    int getData() const;

private:
    int currentHumidity;
};


#endif //SDAT_HUMIDITY_H
