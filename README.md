# lnt-emb-c-activities

[![BUILD](https://github.com/riuandg5/lnt-emb-c-activities/actions/workflows/build.yml/badge.svg)](https://github.com/riuandg5/lnt-emb-c-activities/actions/workflows/build.yml)
[![CODE ANALYSIS](https://github.com/riuandg5/lnt-emb-c-activities/actions/workflows/code-analysis.yml/badge.svg)](https://github.com/riuandg5/lnt-emb-c-activities/actions/workflows/code-analysis.yml)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/6f8a0d749ffa446881a510edcef9d951)](https://app.codacy.com/gh/riuandg5/lnt-emb-c-activities?utm_source=github.com&utm_medium=referral&utm_content=riuandg5/lnt-emb-c-activities&utm_campaign=Badge_Grade_Settings)

This project is part of LnT STEPin program. The objective is to learn Embedded C programming.

For simulation, [SimulIDE](https://www.simulide.com/p/home.html) is used.

# Overview
Objective is to make a Car Seat Heater. The whole project is divided into four different activities.
![overview](images/overview.png)

## Activity 1
* Show status of the heater (ON or OFF) using an LED on the car dashboard.
* Heater can be turned ON or OFF using a switch only if the seat is occupied.
* Occupancy of the seat is known by a sensor.

### In Action
* `DASHBOARD_LED`
    * Show heater status.
    * Connected to `B0`.
* `HEATER_SWITCH`
    * Switch to turn heater ON or OFF.
    * Connected to `D0`.
* `BUTTON_SENSOR`
    * Sensor (emulated as switch) to sense seat occupancy.
    * Connected to `D1`.

| Case 00                            | Case 01                            |
|------------------------------------|------------------------------------|
| ![case 00](images/activity1_1.png) | ![case 01](images/activity1_2.png) |

| Case 10                            | Case 11                            |
|------------------------------------|------------------------------------|
| ![case 10](images/activity1_3.png) | ![case 11](images/activity1_4.png) |

## Activity 2
* Read temperature from a temperature sensor (analog).

### In Action
* `TEMPERATURE_SENSOR`
    * Sensor (emulated as potentiometer) to sense temperature.
    * Give analog signal (voltage from 0V to 5V) for sensed temperature.
    * Connected to `C0`.

| Test Case                         | Output              | Expected Output |
|-----------------------------------|---------------------|-----------------|
| ![test 0](images/activity2_1.png) | (0000000000) 0V     | 0V              |
| ![test 0](images/activity2_2.png) | (0111111111) 2.495V | 2.5V            |
| ![test 0](images/activity2_3.png) | (1111111110) 4.990V | 5V              |