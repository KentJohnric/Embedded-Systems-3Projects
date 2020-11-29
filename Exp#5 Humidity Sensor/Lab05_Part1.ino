#include <dht11.h>
dht11 DHT;
#define DHT_pin 3
void setup() {
  Serial.begin(9600);
}

void loop() {
  DHT.read(DHT_pin);
  Serial.print("Humidity: ");
  Serial.print(DHT.humidity, 1);
  Serial.println("%");
  delay(500);
}
