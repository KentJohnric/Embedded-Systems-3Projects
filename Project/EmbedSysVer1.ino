#include <RFID.h>
#include <Servo.h>
#include <dht.h>
#include <SPI.h>
#include <RFID.h>
#define DHT11_PIN 3
#define SS_PIN 10
#define RST_PIN 9
#define redLED 4
#define greenLED 6
#define blueLED 7
#define relay 2
dht DHT;
bool mainser = true;
int doorOC;
int plugOC = 0;
Servo myservo;
int angle = 0;
#define servoPin 5
RFID rfid(SS_PIN,RST_PIN);


int led = 7;
int power = 8; 
int serNum[5];
int cards[][5] = {
  {169,138,125,178,236}
};

bool access = false;

void setup(){

    Serial.begin(9600);
    SPI.begin();
    rfid.init();
    myservo.attach(servoPin); 
    myservo.write(0);
    pinMode(redLED, OUTPUT);
    pinMode(greenLED, OUTPUT);
    pinMode(blueLED, OUTPUT);
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);
    pinMode(relay, OUTPUT);
    digitalWrite(relay, HIGH);
}

void loop(){
    
    if(rfid.isCard()){
    
        if(rfid.readCardSerial()){
            for(int x = 0; x < sizeof(cards); x++){
              for(int i = 0; i < sizeof(rfid.serNum); i++ ){
                  if(rfid.serNum[i] != cards[x][i]) {
                      access = false;
                      break;
                  } else {
                      access = true;
                  }
              }
              if(access) break;
            }
           
        }
        
       if(access){
          doorOpen();
          delay(500);
          mainFunc();
           
      } else {
          doorClose();
           Serial.println("error");       
       }        
    }  
    rfid.halt();
}
void doorOpen(){
  for(angle = 0; angle <= 180; angle += 1){
    myservo.write(angle);
  }
  doorOC = 1;
}
void doorClose(){
  for(angle = 180; angle >= 0; angle -= 1){
    myservo.write(angle);
  }
  digitalWrite(redLED, HIGH);
  delay(500);
  digitalWrite(redLED, LOW);
  doorOC = 0;
}
void mainFunc(){
  while(mainser){
    int chk = DHT.read11(DHT11_PIN);
    int phsensor = analogRead(A0);
    String data = String(DHT.humidity, 1) + "A" + String(DHT.temperature, 1) + "B" + String(doorOC) + "C" + String(phsensor) + "D" + String(plugOC) + "F";
    Serial.println(data);
    if(Serial.available()){
      int data1 = Serial.read();
      if(data1 == 'Q'){
        doorOpen();
      }
      else if(data1 == 'W'){
        doorClose();
      }
      else if(data1 == 'E'){
        digitalWrite(redLED, HIGH);
      }
      else if(data1 == 'R'){
        digitalWrite(greenLED, HIGH);
      }
      else if(data1 == 'T'){
        digitalWrite(blueLED, HIGH);
      }
      else if(data1 == 'Y'){
        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, LOW);
        digitalWrite(blueLED, LOW);
      }
      else if(data1 == 'U'){
        digitalWrite(relay, LOW);
        plugOC = 1;
      }
      else if(data1 == 'I'){
        digitalWrite(relay, HIGH);
        plugOC = 0;
      }
    }
    delay(2000);
  }
}
