#include <avr/io.h>
#include "utility.h"
#include "activity1.h"
#include "activity2.h"

uint16_t temperature;

void setup();
void loop();

int main()
{
    setup();
    loop();

    return 0;
}

void setup()
{
    init_activity_1();
    init_activity_2();
}

void loop()
{
    while (1)
    {
        if (BUTTON_SENSOR_ON && HEATER_SWITCH_ON)
        {
            set_dashboard_led(ON);
            temperature = read_temperature_sensor();
        }
        else
        {
            set_dashboard_led(OFF);
        }
    }
}