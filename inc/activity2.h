/**
 * @file activity1.h
 * @author Rishu Anand
 * @brief Configurations and functions for Activity2
 * @version 0.1
 * @date 2021-05-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __ACTIVITY2_H__
#define __ACTIVITY2_H__

#define TEMPERATURE_SENSOR_CHANNEL 0 /**< Temperature Sensor analog channel */

/**
 * @brief Initialize Temperature Sensor for Activity2
 * 
 */
void init_activity_2();

/**
 * @brief Read temperature from analog Temperature Sensor
 * 
 * @return uint16_t Temperature data
 */
uint16_t read_temperature_sensor();

#endif /** __ACTIVITY2_H__ */