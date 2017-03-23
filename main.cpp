#include <iostream>
#include <unistd.h>
#include "imx6.h"

using namespace std;

int main (void)
{
    IMX6* imx6 = new IMX6();

    cout << "Turning on red LED to indicate temperature is being read..." << endl;
    imx6->ledOn();

    double currentTemperature;

    for (int i = 0; i < 10; i++) {
        currentTemperature = imx6->getCurrentTemperature();
	printf("Current temperature: %.3f\n", currentTemperature);
        sleep(1);
    }
    
    cout << "Turning off red LED to indicate temperature is no longer being read..." << endl;
    imx6->ledOff();

    cout << "Sleeping for a couple seconds for the next bit..." << endl;
    sleep(2);

    cout << "Turning red LED on for the heckovit..." << endl;
    imx6->ledOn();
    if (imx6->ledStatus() == 1)
        cout << "It's on!" << endl;
    else
        cout << "ERROR:  It's off!  Strange, that wasn't supposed to happen!" << endl;

    sleep(3);

    cout << "Turning red LED off for the heckovit..." << endl;
    imx6->ledOff();
    if (imx6->ledStatus() == 0)
        cout << "It's off!" << endl;
    else 
        cout << "ERROR:  It's off!  Strange, that wasn't supposed to happen!" << endl;

    return 0;
}
