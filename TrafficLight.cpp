#include "TrafficLight.h"

TrafficLight::TrafficLight(byte red, byte green, byte yellow)
{
    this->red = new LED(red);
    this->green = new LED(green);
    this->yellow = new LED(yellow);
}

void TrafficLight::onAll()
{
    red->on();
    green->on();
    yellow->on();
}

void TrafficLight::offAll()
{
    red->off();
    green->off();
    yellow->off();
}