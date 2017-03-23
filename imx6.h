#ifndef IMX6_H
#define IMX6_H

using namespace std;

class IMX6
{
public:
    IMX6();

    int ledOn();
    int ledOff();
    int ledHeartbeat();
    int ledStatus(); 
    double getCurrentTemperature();
};

#endif
