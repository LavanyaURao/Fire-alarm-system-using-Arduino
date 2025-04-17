#include <DHT.h>

#define DHTPIN 2            
#define DHTTYPE DHT11

#define BUZZER 4            
#define FLAME_PIN 8         
#define SMOKE_PIN A1        

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("🔥 Fire Hazard Detection System");

  dht.begin();

  pinMode(BUZZER, OUTPUT);
  pinMode(FLAME_PIN, INPUT);
}

void loop() {
  float temperature = dht.readTemperature();
  int flameState = digitalRead(FLAME_PIN);     
  int smokeLevel = analogRead(SMOKE_PIN);      

  if (isnan(temperature)) {
    Serial.println("❌ Failed to read from DHT11 sensor!");
    return;
  }

  // Define thresholds
  int tempThreshold = 25;
  int smokeThreshold = 150;

  // Evaluate conditions
  bool tempHigh = (temperature >= tempThreshold);
  bool flameDetected = (flameState == 0);
  bool smokeDetected = (smokeLevel >= smokeThreshold);

  // Print sensor data with conditions
  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print("°C");
  Serial.print(tempHigh ? " ✅" : " ❌ (<");
  if (!tempHigh) Serial.print(tempThreshold);
  if (!tempHigh) Serial.print(")");

  Serial.print(" | Flame: ");
  Serial.print(flameDetected ? "🔥 (Detected)" : "✅ No Flame ❌");

  Serial.print(" | Smoke: ");
  Serial.print(smokeLevel);
  Serial.print(smokeDetected ? " ✅" : " ❌ (<");
  if (!smokeDetected) Serial.print(smokeThreshold);
  if (!smokeDetected) Serial.print(")");

  Serial.println();

  // Check if ALL conditions are met
  if (tempHigh && flameDetected && smokeDetected) {
    Serial.println("🚨 ALERT! All conditions met. Buzzer ON.");
    digitalWrite(BUZZER, HIGH);
  } else {
    Serial.println("ℹ️ Buzzer OFF. Conditions not fully met.");
    digitalWrite(BUZZER, LOW);
  }

  delay(2000);
}
