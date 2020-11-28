#define led 3

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensor_value = analogRead(A0);
  Serial.print("PhotoCell Raw Value = ");
  Serial.println(sensor_value);
  int photosensor = 1023 - sensor_value;
  int LEDpower = map(photosensor, 0, 1023, 0, 255);
  analogWrite(led, LEDpower);
  delay(100);  
}
