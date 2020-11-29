#include <DHT.h>
#define DHTpin 2
#define DHTTYPE DHT11
DHT dht(DHTpin, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Lab04 Temperature Sensor");
  dht.begin();
}

void loop() {
  delay(1000);
  float celcius = dht.readTemperature();

  Serial.print("Temperature: ");
  Serial.println(celcius);
}
