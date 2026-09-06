 --Smart Home Environment Monitoring System--

About the Project:
       This project is an Arduino-based Smart Home Environment Monitoring System.
       It monitors:
     Temperature, Humidity, Light, Distance.
     The sensor values are displayed on a 16×2 I2C LCD and Serial Monitor.
     The Arduino reads temperature, humidity, light intensity and distance and displays the values on the LCD and Serial Monitor during Normal Condition.
     When an abnormal condition is detected, the warning LED and buzzer are turned ON.

 Components Used:
      - Arduino UNO
      - DHT22 Sensor
      - LDR Sensor
      - HC-SR04 Ultrasonic Sensor
      - 16×2 I2C LCD
      - Buzzer
      - 2 LEDs
      - 2 × 220Ω Resistors

 Pin Connections:
     Components:-
      - Arduino UNO 
      - DHT22 : D2 
      - HC-SR04 TRIG : D3 
      - HC-SR04 ECHO : D4 
      - Buzzer : D5 
      - Normal LED :  D6 
      - Warning LED :  D7 
      - LDR :  A0 
      - LCD SDA :  A4 
      - LCD SCL :  A5 

  Working:     
      1. DHT22 measures temperature and humidity.
      2. LDR measures light intensity.
      3. HC-SR04 measures distance.
      4. Arduino processes the sensor values.
      5. Values are displayed on the LCD and Serial Monitor.
      6. If a warning condition occurs, the warning LED and buzzer turn ON.
      7. During normal conditions, the normal LED remains ON.

  Testing:
      Normal Condition:-
        The system displays the sensor readings and the normal LED is ON.
      Warning Condition:-
        When an abnormal value is detected, the warning LED and buzzer are activated.

 Simulation:
    The project was designed and tested using Wokwi.
    Wokwi Project:
      https://wokwi.com/projects/474406565831983105

 Software Used
    - Arduino
    - Wokwi Simulator
    - DHT Sensor Library
    - LiquidCrystal I2C Library



      



