// Hay que usar el Serial Monitor (Ctrl + Shift + M) para ver el resultado
// Lectura del sensor de humedad de suelo:
// Tierra Muy húmeda:
// Tierra Húmeda: ~600
// Tierra seca: ~400
// Tierra muy seca:

// Posibles mejoras:
// Añadir tiempos de espera entre cambios de estado

// Include the libraries:
#include <Adafruit_Sensor.h>
#include <DHT.h>

// DEFINES
#define DHT_PIN         4
#define SOIL_PIN        A0
#define AVG             8
#define DHT_TYPE         DHT11   // DHT 11 
#define HIGH_HUMIDITY   60.0
#define LOW_HUMIDITY    55.0

#define UPDATE_TIME     5000 // milliseconds

float h; // Relative humidity
float t; // Temperature in ºC
int s;  // Soil humidity sensor reading
float averaging;
int i;
// Initialize DHT sensor for normal 16mhz Arduino:
DHT dht = DHT(DHT_PIN, DHT_TYPE);
void setup() {
  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);
  //Serial.println("System Started");
  // Setup sensor:
  dht.begin();
}
void loop() {
  // Wait a few seconds between measurements:
  delay(UPDATE_TIME);
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  // Read the humidity in %:
  h = dht.readHumidity();
  // Read the temperature as Celsius:
  t = dht.readTemperature();
  averaging = 0.0;
  for (i = 0;i < AVG;i++){
    // Read the soil sensor
    s = analogRead(SOIL_PIN);
    averaging = averaging + s / AVG;
  }
  // Check if any reads failed and exit early (to try again):
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // Compute heat index in Celsius:
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(t);
  Serial.print("\xC2\xB0");
  Serial.print("C, ");
  Serial.print((int) h);
  Serial.print("%, ");
  Serial.print((int) averaging);
  Serial.println(" SH");

}
