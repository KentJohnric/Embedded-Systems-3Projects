#define pot A0
#define blue 10
#define green 11
int potVal;
int percent;
int pwm1;
int pwm2;

void setup() {
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(pot);
  percent = map(potVal, 0, 1023, 0, 100);
  pwm1 = map(potVal, 0, 1023, 0, 255);
  pwm2 = map(potVal, 0, 1023, 255, 0);
  Serial.println("Analog Pin Reading: ");
  Serial.println(potVal);
  Serial.println("Potentiometer %: ");
  Serial.println(percent);
  analogWrite(blue, pwm1);
  analogWrite(green, pwm2);
  delay(1000);
}
