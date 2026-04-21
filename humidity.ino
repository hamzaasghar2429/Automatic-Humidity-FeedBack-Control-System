#include <DHT.h>

// ---------- PIN CONFIG ----------
#define DHTPIN 8
#define DHTTYPE DHT11

#define FAN_PIN 9
#define ALARM_PIN 13

// ---------- VARIABLES ----------
float lowerHumidity = 60.0;
float upperHumidity = 80.0;
float humidity;

// Create DHT object
DHT dht(DHTPIN, DHTTYPE);

// ---------- SETUP ----------
void setup() {
  pinMode(FAN_PIN, OUTPUT);
  pinMode(ALARM_PIN, OUTPUT);

  digitalWrite(FAN_PIN, LOW);
  digitalWrite(ALARM_PIN, LOW);

  Serial.begin(9600);
  dht.begin();

  Serial.println("Humidity Control System Initializing...");
  delay(2000);
}

// ---------- LOOP ----------
void loop() {

  humidity = dht.readHumidity();

  // Check if sensor reading failed
  if (isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }
}