#ifndef TrafficLight_H
#define TrafficLight_H

#include <ArduinoJson.h>
#include "LED.h"

class TrafficLight
{
public:
    LED *red;
    LED *green;
    LED *yellow;

    TrafficLight(byte red, byte green, byte yellow);
    void onAll();
    void offAll();
};

#endif