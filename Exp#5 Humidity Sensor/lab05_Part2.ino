#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <dht11.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); 
dht11 DHT;
#define DHT_pin 3
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  DHT.read(DHT_pin);
  Serial.print("Humidity: ");
  lcd.print("Humidity: ");
  lcd.setCursor(0, 1);
  Serial.print(DHT.humidity, 1);
  lcd.print(DHT.humidity, 1);
  Serial.println("%");
  lcd.println("%");
  delay(500);
}
