#define a 2
#define b 3
#define c 4
#define d 5
#define e 6
#define f 7
#define g 8
#define led 3
int COUNT = 0;
void setup() {
  for(int i = 2; i < 9; i++){
    pinMode(i,OUTPUT);
  }
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensor_value = analogRead(A0);
  Serial.print("PhotoCell Raw Value = ");
  Serial.println(sensor_value);
  int photosensor = 1023 - sensor_value;
  int LEDpower = map(photosensor, 0, 1023, 0, 255);
  switch(COUNT){
    case 0:
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, HIGH);
      break;
    case 1:
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    case 2:
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, LOW);
      break;
    case 3:
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, LOW);
      break;
    case 4:
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      break;
    case 5:
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, HIGH);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      break;
    case 6:
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      break;
    case 7:
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    case 8:
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      break;
    case 9:
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, HIGH);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      break;
  }
  if (COUNT < 10){
    if (sensor_value > 500){
      COUNT++;
    }
  }
  else if(COUNT >= 10){
    COUNT = 0;
  }
  delay(500);
}  
