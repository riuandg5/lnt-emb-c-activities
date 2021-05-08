/**
 * @file activity1.h
 * @author Rishu Anand
 * @brief Configurations and functions for Activity1
 * @version 0.1
 * @date 2021-05-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __ACTIVITY1_H__
#define __ACTIVITY1_H__

#define HEATER                   /**< Heater configuration */
#define HEATER_PORT D            /**< Heater port */
#define HEATER_PIN 0             /**< Heater pin */
#define HEATER_ON !(PIN(HEATER)) /**< Heater state */

#define BUTTON_SENSOR                          /**< Button Sensor configuration */
#define BUTTON_SENSOR_PORT D                   /**< Button Sensor port */
#define BUTTON_SENSOR_PIN 1                    /**< Button Sensor pin */
#define BUTTON_SENSOR_ON !(PIN(BUTTON_SENSOR)) /**< Button Sensor state */

#define LED        /**< LED configuration */
#define LED_PORT B /**< LED port */
#define LED_PIN 0  /**< LED pin */

/**
 * @brief Initialize LED as output and Heater and Button Sensor as input
 * 
 */
void init_led();

/**
 * @brief Set LED state
 * 
 * @param state ON or OFF
 */
void set_led(int state);

#endif /** __ACTIVITY1_H__ */