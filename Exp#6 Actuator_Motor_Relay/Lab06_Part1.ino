#define Relay_pin 3
void setup() {
  pinMode(Relay_pin, OUTPUT);
}

void loop() {
  digitalWrite(Relay_pin, HIGH);
  delay(1000);
  digitalWrite(Relay_pin, LOW);
  delay(1000);
}
