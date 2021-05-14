#include <avr/io.h>
#include "utility.h"
#include "activity2.h"

static void init_adc();
static void read_adc(uint8_t channel);

void init_activity_2()
{
    init_adc();
}

uint16_t read_temperature_sensor()
{
    read_adc(TEMPERATURE_SENSOR_CHANNEL);

    return (ADC);
}

static void init_adc()
{
    set_bit_state(&ADMUX, REFS1, OFF);
    set_bit_state(&ADMUX, REFS0, ON);
    
    set_bit_state(&ADMUX, ADLAR, OFF);

    set_bit_state(&ADCSRA, ADPS2, ON);
    set_bit_state(&ADCSRA, ADPS1, ON);
    set_bit_state(&ADCSRA, ADPS0, ON);

    set_bit_state(&ADCSRA, ADEN, ON);
}

static void read_adc(uint8_t channel)
{
    ADMUX &= 0xf0;
    channel &= 0x07;
    ADMUX |= channel;

    set_bit_state(&ADCSRA, ADSC, ON);

    while (!get_bit_state(&ADCSRA, ADSC))
        ;
}