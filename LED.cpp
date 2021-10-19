#include "LED.h"

LED::LED(byte pin)
{
    this->pin = pin;
    init();
}

void LED::init()
{
    pinMode(pin, OUTPUT);
    off();
}

void LED::off()
{
    digitalWrite(pin, LOW);
}

void LED::on()
{
    digitalWrite(pin, HIGH);
}