#include <avr/io.h>
#include "utility.h"
#include "activity1.h"

static void init_heater_switch();
static void init_button_sensor();
static void init_dashboard_led();

void init_activity_1()
{
    init_heater_switch();
    init_button_sensor();
    init_dashboard_led();
}

void set_dashboard_led(int state)
{
    switch (state)
    {
    case ON:
        set_bit_state(&DASHBOARD_LED_PORTx, DASHBOARD_LED_BIT, ON);
        break;
    case OFF:
        set_bit_state(&DASHBOARD_LED_PORTx, DASHBOARD_LED_BIT, OFF);
        break;
    default:
        break;
    }
}

static void init_heater_switch()
{
    set_bit_state(&HEATER_SWITCH_DDRx, HEATER_SWITCH_BIT, OFF);
    set_bit_state(&HEATER_SWITCH_PORTx, HEATER_SWITCH_BIT, ON);
}

static void init_button_sensor()
{
    set_bit_state(&BUTTON_SENSOR_DDRx, BUTTON_SENSOR_BIT, OFF);
    set_bit_state(&BUTTON_SENSOR_PORTx, BUTTON_SENSOR_BIT, ON);
}

static void init_dashboard_led()
{
    set_bit_state(&DASHBOARD_LED_DDRx, DASHBOARD_LED_BIT, ON);
    set_bit_state(&DASHBOARD_LED_PORTx, DASHBOARD_LED_BIT, OFF);
}