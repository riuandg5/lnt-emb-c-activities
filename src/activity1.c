#include <avr/io.h>
#include "utility.h"
#include "activity1.h"

void init_led()
{
    DDR(HEATER, INPUT);
    PORT(HEATER, SET_BIT);

    DDR(BUTTON_SENSOR, INPUT);
    PORT(BUTTON_SENSOR, SET_BIT);

    DDR(LED, OUTPUT);
    PORT(LED, CLEAR_BIT);
}

void set_led(int state)
{
    if (state == ON)
    {
        PORT(LED, SET_BIT);
    }
    if (state == OFF)
    {
        PORT(LED, CLEAR_BIT);
    }
}