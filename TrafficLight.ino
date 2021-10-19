// Wala akong breadboard kaya ganyan na lang muna HAHAHAH

#include "LED.h"
#include "TrafficLight.h"

#define LED_PIN_1 2
#define LED_PIN_2 3
#define LED_PIN_3 4
#define LED_PIN_4 5
#define LED_PIN_5 6
#define LED_PIN_6 7

#define SHORT 100
#define LONG 500

TrafficLight *t1;
TrafficLight *t2;

void setup()
{
    t1 = new TrafficLight(LED_PIN_1, LED_PIN_2, LED_PIN_3);
    t2 = new TrafficLight(LED_PIN_4, LED_PIN_5, LED_PIN_6);
}

void loop()
{
    testTraffic1(t1, t2);
    testTraffic2(t1, t2);
    testSOS(t1, t2);
}

void testLED(LED *led)
{
    led->on();
    delay(1000);
    led->off();
    delay(1000);
}

void shortBlink(TrafficLight *t)
{
    t->onAll();
    delay(SHORT);
    t->offAll();
    delay(SHORT);
}

void longBlink(TrafficLight *t)
{
    t->onAll();
    delay(LONG);
    t->offAll();
    delay(LONG);
}

void testTraffic1(TrafficLight *t1, TrafficLight *t2)
{
    t1->onAll();
    t2->onAll();
    delay(1000);
    t1->offAll();
    t2->offAll();
    delay(1000);
}

void testTraffic2(TrafficLight *t1, TrafficLight *t2)
{
    // T1: RED, T2: GREEN
    t1->red->on();
    t1->green->off();
    t1->yellow->off();
    t2->red->off();
    t2->green->off();
    t2->yellow->on();
    delay(1000);

    // T1: YELLOW, T2: YELLOW
    t1->red->off();
    t1->green->on();
    t1->yellow->off();
    t2->red->off();
    t2->green->on();
    t2->yellow->off();
    delay(1000);

    // T1: GREEN, T2: RED
    t1->red->off();
    t1->green->off();
    t1->yellow->on();
    t2->red->on();
    t2->green->off();
    t2->yellow->off();
    delay(1000);

    testTraffic1(t1, t2);
}

void testSOS(TrafficLight *t1, TrafficLight *t2)
{
    // T1: 3X SHORT BLINK -> 3X LONG BLINK -> 3X SHORT BLINK
    t2->offAll();
    SOS(t1);
    // T2: 3X SHORT BLINK -> 3X LONG BLINK -> 3X SHORT BLINK
    t1->offAll();
    SOS(t2);
}

void SOS(TrafficLight *t)
{
    for (int i = 0; i < 3; i++)
    {
        shortBlink(t);
    }
    delay(500);
    for (int i = 0; i < 3; i++)
    {
        longBlink(t);
    }
    for (int i = 0; i < 3; i++)
    {
        shortBlink(t);
    }
    delay(500);
}
