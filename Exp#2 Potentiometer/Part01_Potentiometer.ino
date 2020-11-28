#define pot A0
int potVal;
int percent;

void setup() {
  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(pot);
  percent = map(potVal, 0, 1023, 0, 100);

  Serial.println("Analog Pin Reading: ");
  Serial.println(potVal);
  Serial.println("Potentiometer %: ");
  Serial.println(percent);
  delay(1000);
}
