#include <avr/io.h>
#include "utility.h"

void set_bit_state(volatile uint8_t *reg, int bit, int state)
{
    switch (state)
    {
    case ON:
        *reg |= (1 << bit);
        break;
    case OFF:
        *reg &= ~(1 << bit);
        break;
    default:
        break;
    }
}

int get_bit_state(volatile uint8_t *reg, int bit)
{
    return (*reg & (1 << bit)) >> bit;
}