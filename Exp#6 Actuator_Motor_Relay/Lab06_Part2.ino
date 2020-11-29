#define Relay_pin 3
void setup() {
  Serial.begin(9600);
  pinMode(Relay_pin, OUTPUT);
  Serial.println("1/0 test with relay");
  digitalWrite(Relay_pin, HIGH);
}

void loop() {
  if(Serial.available() > 0){
    int inpS = Serial.read();
    switch (inpS){
      case '1':
        digitalWrite(Relay_pin, LOW);
        break;
      case '0':
        digitalWrite(Relay_pin, HIGH);
        break;
    }
  }
}
