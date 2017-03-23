#include <fstream>
#include <string>
#include <iostream>
#include "imx6.h"

using namespace std;

IMX6::IMX6() { }

int IMX6::ledOn()
{
    ofstream led("/sys/class/leds/red-led/brightness");
    if (led < 0) {
        cout << "Failed to open led!\n";
        return -1;
    }

    led << 1;
    led.close();

    return 0;
}

int IMX6::ledOff()
{
    ofstream led("/sys/class/leds/red-led/brightness");
    if (led < 0) {
        cout << "Failed to open led!" << endl;
        return -1;
    }

    led << 0;
    led.close();

    return 0;
}

int IMX6::ledHeartbeat()
{
    ofstream led("/sys/class/leds/red-led/brightness");
    if (led < 0) {
        cout << "Failed to open led!" << endl;
        return -1;
    }

    led << "heartbeat";
    led.close();

    return 0;
}

int IMX6::ledStatus()
{
    string val;

    ifstream led("/sys/class/leds/red-led/brightness");
    if (led < 0) {
        cout << "Failed to open led!" << endl;
        return -1;
    }

    led >> val;

    led.close();

    return std::stoi(val);
}

double IMX6::getCurrentTemperature()
{
    string val;
    string preparedTemp;
    double temperature;

    ifstream temperatureFile ("/sys/class/thermal/thermal_zone0/temp");

    if (temperatureFile < 0) {
        cout << "Failed to open temperatureFile!\n";
        return -1;
    }

    // The temperature is stored in 5 digits.  The first two are degrees in C.  The rest are decimal precision.
    temperatureFile >> val;

    temperatureFile.close();

    preparedTemp = val.insert(2, 1, '.');
    temperature = std::stod(preparedTemp);

    return temperature;
}

