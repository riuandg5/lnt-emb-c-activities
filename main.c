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
    init_led();
}

void loop()
{
    while (1)
    {
        if (BUTTON_SENSOR_ON)
        {
            if (HEATER_ON)
            {
                set_led(ON);
            }
            else
            {
                set_led(OFF);
            }
        }
        else
        {
            set_led(OFF);
        }
    }
}