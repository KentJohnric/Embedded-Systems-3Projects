#define potPin A0
#define redPin 11
#define greenPin 10
#define bluePin 9
int potValue;
int redValue, greenValue, blueValue;
int percent;

void setup() {
  Serial.begin(9600);
}
void loop() {
  potValue = analogRead(potPin); 
  setRGB(potValue);
  percent = map(potValue, 0, 1023, 0, 100);
  Serial.println("Potentiometer %: ");
  Serial.println(percent);
}

void setRGB(int RGBposition) { 
  int mapRGB1, mapRGB2, constrained1, constrained2;

  mapRGB1 = map(RGBposition, 0, 341, 255, 0);
  constrained1 = constrain(mapRGB1, 0, 255);
  mapRGB2 = map(RGBposition, 682, 1023, 0, 255);
  constrained2 = constrain(mapRGB2, 0, 255);

  redValue = constrained1 + constrained2;
  greenValue = constrain(map(RGBposition, 0, 341, 0, 255), 0, 255)
                - constrain(map(RGBposition, 341, 682, 0,255), 0, 255);
  blueValue = constrain(map(RGBposition, 341, 682, 0, 255), 0, 255)
                - constrain(map(RGBposition, 682, 1023, 0, 255), 0, 255);

  analogWrite(redPin, redValue); 
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
