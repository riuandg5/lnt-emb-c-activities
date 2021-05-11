#include <avr/io.h>
#include "utility.h"
#include "activity1.h"

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
}

void loop()
{
    while (1)
    {
        if (BUTTON_SENSOR_ON && HEATER_SWITCH_ON)
        {
            set_dashboard_led(ON);
        }
        else
        {
            set_dashboard_led(OFF);
        }
    }
}