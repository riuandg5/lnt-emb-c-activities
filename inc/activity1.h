/**
 * @file activity1.h
 * @author Rishu Anand
 * @brief Configurations and functions for Activity1
 * @version 0.2
 * @date 2021-05-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __ACTIVITY1_H__
#define __ACTIVITY1_H__

#define HEATER_SWITCH_DDRx DDRD   /**< Heater Switch data direction register */
#define HEATER_SWITCH_PORTx PORTD /**< Heater Switch data register */
#define HEATER_SWITCH_PINx PIND   /**< Heater Switch port input register */
#define HEATER_SWITCH_BIT 0       /**< Heater Switch bit number */

#define BUTTON_SENSOR_DDRx DDRD   /**< Button Sensor data direction register */
#define BUTTON_SENSOR_PORTx PORTD /**< Button Sensor data register */
#define BUTTON_SENSOR_PINx PIND   /**< Button Sensor input register */
#define BUTTON_SENSOR_BIT 1       /**< Button Sensor bit number */

#define DASHBOARD_LED_DDRx DDRB   /**< Dashboard LED data direction register */
#define DASHBOARD_LED_PORTx PORTB /**< Dashboard LED data register */
#define DASHBOARD_LED_PINx PINB   /**< Dashboard LED port input register */
#define DASHBOARD_LED_BIT 0       /**< Dashboard LED bit number */

#define HEATER_SWITCH_ON !get_bit_state(&HEATER_SWITCH_PINx, HEATER_SWITCH_BIT) /**< Get Heater Switch state */
#define BUTTON_SENSOR_ON !get_bit_state(&BUTTON_SENSOR_PINx, BUTTON_SENSOR_BIT) /**< Get Button Sensor state */

/**
 * @brief Initialize Heater Switch, Button Sensor and Dashboard LED for Activity1
 * 
 */
void init_activity_1();

/**
 * @brief Set the state of Dashboard LED
 * 
 * @param state ON or OFF
 */
void set_dashboard_led(int state);

#endif /** __ACTIVITY1_H__ */