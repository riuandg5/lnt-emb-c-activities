/**
 * @file utility.h
 * @author Rishu Anand
 * @brief Common utilities
 * @version 0.1
 * @date 2021-05-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __UTILITY_H__
#define __UTILITY_H__

#define ON 1  /**< ON state */
#define OFF 0 /**< OFF state */

#define SET_BIT |=    /**< OR operation to set bit */
#define CLEAR_BIT &= ~/**< AND operation after NOT to clear bit */
#define TOGGLE_BIT ^= /**< XOR operation to toggle bit */

#define OUTPUT SET_BIT  /**< OUTPUT (1) pin mode */
#define INPUT CLEAR_BIT /**< INPUT (0) pin mode */

#define DDR__(port) DDR##port  /**< Make DDR register ex. DDRB, DDRC, DDRD */
#define DDR_(port) DDR__(port) /**< Helper macro to make DDR register */
#define DDR(device, direction) \
    DDR_(device##_PORT)        \
    direction(1 << device##_PIN) /**< Set direction of pin */

#define PORT__(port) PORT##port  /**< Make PORT register ex. PORTB, PORTC, PORTD */
#define PORT_(port) PORT__(port) /**< Helper macro to make PORT register */
#define PORT(device, operation) \
    PORT_(device##_PORT)        \
    operation(1 << device##_PIN) /**< Write bit to pin */

#define PIN__(port) PIN##port  /**< Make PIN register ex. PINB, PINC, PIND */
#define PIN_(port) PIN__(port) /**< Helper macro to make PIN register */
#define PIN(device) \
    PIN_(device##_PORT) & (1 << device##_PIN) /**< Read bit from pin */

#endif /** __UTILITY_H__ */