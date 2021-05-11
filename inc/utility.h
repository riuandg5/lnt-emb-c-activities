/**
 * @file utility.h
 * @author Rishu Anand
 * @brief Common utilities
 * @version 0.2
 * @date 2021-05-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __UTILITY_H__
#define __UTILITY_H__

#define ON 1  /**< ON state */
#define OFF 0 /**< OFF state */

/**
 * @brief Set the bit state in a register
 * 
 * @param reg Register to modify
 * @param bit Bit position to modify
 * @param state Bit value
 */
void set_bit_state(volatile uint8_t *reg, int bit, int state);

/**
 * @brief Get the bit state in a register
 * 
 * @param reg Register to read
 * @param bit Bit position to read
 * @return int Bit value
 */
int get_bit_state(volatile uint8_t *reg, int bit);

#endif /** __UTILITY_H__ */