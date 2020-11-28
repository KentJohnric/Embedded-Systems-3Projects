#define Bled 3
#define Gled 5

void setup() {
  pinMode(Bled, OUTPUT);
  pinMode(Gled, OUTPUT);
  Serial.begin(9600);
  Serial.println("type blue to turn on Blue LED and green for Green LED");
  digitalWrite(Bled, HIGH);
  digitalWrite(Gled, HIGH);
  delay(1000);
  digitalWrite(Bled, LOW);
  digitalWrite(Gled, LOW);
  delay(1000);
}

void loop() {
  if (Serial.available()> 0){
    char inData = char(Serial.read());
    if(inData == 'b'){
      Serial.println("Blue LED in ON");
      digitalWrite(Bled, HIGH);
      digitalWrite(Gled, LOW);
    }
    else if(inData == 'g'){
      Serial.println("Green LED is ON");
      digitalWrite(Gled, HIGH);
      digitalWrite(Bled, LOW);
    }
  }
}
