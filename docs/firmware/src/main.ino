#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME680.h>

Adafruit_BME680 bme;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  if (!bme.begin()) {
    Serial.println("BME680 non détecté.");
    while (1);
  }

  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
}

void loop() {
  if (!bme.performReading()) {
    Serial.println("Erreur de lecture du capteur.");
    return;
  }

  Serial.print("Temperature: ");
  Serial.println(bme.temperature);

  Serial.print("Humidity: ");
  Serial.println(bme.humidity);

  Serial.print("Pressure: ");
  Serial.println(bme.pressure / 100.0);

  Serial.print("Gas Resistance: ");
  Serial.println(bme.gas_resistance / 1000.0);

  delay(2000);
}

