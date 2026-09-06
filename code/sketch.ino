#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ---------------- PIN DEFINITIONS ----------------

#define DHTPIN 2
#define DHTTYPE DHT22

#define TRIG_PIN 3
#define ECHO_PIN 4

#define BUZZER_PIN 5

#define NORMAL_LED 6
#define WARNING_LED 7

#define LDR_PIN A0

// ---------------- OBJECTS ----------------

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

// ---------------- SETUP ----------------

void setup() {

  Serial.begin(9600);

  dht.begin();

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(BUZZER_PIN, OUTPUT);

  pinMode(NORMAL_LED, OUTPUT);
  pinMode(WARNING_LED, OUTPUT);

  pinMode(LDR_PIN, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Smart Home");
  lcd.setCursor(0, 1);
  lcd.print("Monitoring");

  delay(2000);

  lcd.clear();

  Serial.println("================================");
  Serial.println(" Smart Home Monitoring System");
  Serial.println("================================");
}

// ---------------- DISTANCE FUNCTION ----------------

float getDistance() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  float distance = duration * 0.0343 / 2;

  return distance;
}

// ---------------- MAIN LOOP ----------------

void loop() {

  // Read temperature and humidity
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Read light
  int lightValue = analogRead(LDR_PIN);

  // Read distance
  float distance = getDistance();

  // Check whether DHT22 reading is valid
  if (isnan(temperature) || isnan(humidity)) {

    Serial.println("DHT22 reading failed!");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DHT22 Error");

    delay(2000);

    return;
  }

  // ---------------- SERIAL MONITOR ----------------

  Serial.println("--------------------------------");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Light: ");
  Serial.println(lightValue);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // ---------------- WARNING CONDITION ----------------

  bool warning = false;

  // High temperature
  if (temperature > 30) {
    warning = true;
  }

  // High humidity
  if (humidity > 80) {
    warning = true;
  }

  // Low light
  if (lightValue < 300) {
    warning = true;
  }

  // Object too close
  if (distance < 20) {
    warning = true;
  }

  // ---------------- LED + BUZZER ----------------

  if (warning) {

    digitalWrite(NORMAL_LED, LOW);
    digitalWrite(WARNING_LED, HIGH);

    tone(BUZZER_PIN, 1000);

    Serial.println("STATUS: WARNING");

  } else {

    digitalWrite(NORMAL_LED, HIGH);
    digitalWrite(WARNING_LED, LOW);

    noTone(BUZZER_PIN);

    Serial.println("STATUS: NORMAL");
  }

  // ---------------- LCD ----------------

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature, 1);
  lcd.print("C H:");
  lcd.print(humidity, 0);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("L:");
  lcd.print(lightValue);
  lcd.print(" D:");
  lcd.print(distance, 0);
  lcd.print("cm");

  delay(2000);
}