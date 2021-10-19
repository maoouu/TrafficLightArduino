#ifndef LED_H
#define LED_H

#include <ArduinoJson.h>

class LED
{
private:
    byte pin;

public:
    LED(byte pin);
    void init();
    void on();
    void off();
};

#endif