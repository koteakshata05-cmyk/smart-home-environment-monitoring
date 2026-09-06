# Smart Home Environment Monitoring System

## Project Overview

This project is an Arduino-based Smart Home Environment Monitoring System designed to monitor important environmental conditions using different sensors.

## Components Used

- Arduino
- DHT22 Temperature and Humidity Sensor
- LDR Sensor
- HC-SR04 Ultrasonic Sensor
- LCD Display
- LED
- Buzzer

## Working

The sensors collect environmental information such as temperature, humidity, light intensity, and distance.

The Arduino processes the sensor data and displays the required information on the LCD.

If an abnormal condition is detected, the system provides an alert using the LED and buzzer.

## Project Structure

```text
smart-home-environment-monitoring/
│
├── code/
│   └── sketch.ino
│
├── schematics/
│   ├── circuit_connection (1).png
│   ├── normal_condn.png
│   └── warning_codn.png
│
├── diagram.json
├── libraries.txt
└── README.md