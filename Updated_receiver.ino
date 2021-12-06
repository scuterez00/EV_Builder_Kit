#include "Adafruit_LC709203F.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int ReceivedMessage[1] = {000};
RF24 radio(10, 2);
const byte address[6] = "00001";

//Defining the State of Charge Board
Adafruit_LC709203F lc;
//Defining LEDs that will light up to signify battery power
#define Motor1P1 3
#define Motor1P2 4
#define Motor2P2 5
#define Motor2P1 6
#define Full 7
#define Half 8
#define Charge 9

void setup() {
  radio.begin();

  //set the address
  radio.openReadingPipe(0, address);

  //Set module as receiver
  radio.startListening();
  
  Serial.begin(115200);
  delay(10);
  Serial.println("\nMotor And Battery Demo");
  if (!lc.begin()) {
    Serial.println(F("Couldnt find Adafruit LC709203F?\nMake sure a battery is plugged in!"));
    while (1) delay(10);
  }
  Serial.println(F("Found LC709203F"));
  Serial.print("Version: 0x"); Serial.println(lc.getICversion(), HEX);
  lc.setThermistorB(3950);
  lc.setPackSize(LC709203F_APA_3000MAH);

  //Set Output Mode for the Pins
  pinMode(Motor1P1, OUTPUT);
  pinMode(Motor1P2, OUTPUT);
  pinMode(Motor2P1, OUTPUT);
  pinMode(Motor2P2, OUTPUT);
  pinMode(Full,OUTPUT);
  pinMode(Half,OUTPUT);
  pinMode(Charge,OUTPUT);
}

void loop() {
  while (radio.available()) {
    radio.read(ReceivedMessage, 1);

    if (ReceivedMessage[0] == 001) {
      // Both Motors Running Forward Fast
      
      Serial.println("Forward");
      Serial.print("Batt Percent: "); Serial.println(lc.cellPercent(), 1);
      batterycheck(lc.cellPercent());
      digitalWrite(Motor1P1, HIGH);
      digitalWrite(Motor1P2, LOW);
      digitalWrite(Motor2P1, HIGH);
      digitalWrite(Motor2P2, LOW);
      analogWrite(Motor1P1,255);
      analogWrite(Motor2P1,255);
    }
    
    if (ReceivedMessage[0] == 010) {
      // Both Motors Running Forward Slower

      Serial.println("Forward Slow");
      Serial.print("Batt Percent: "); Serial.println(lc.cellPercent(), 1);
      analogWrite(Motor1P1,125);
      analogWrite(Motor2P1,125);
    }
    
    if (ReceivedMessage[0] == 000) {
      // Both Motors Off
      
      Serial.println("Off");
      Serial.print("Batt Percent: "); Serial.println(lc.cellPercent(), 1);
      batterycheck(lc.cellPercent());
      digitalWrite(Motor1P1, LOW);
      digitalWrite(Motor1P2, LOW);
      digitalWrite(Motor2P1, LOW);
      digitalWrite(Motor2P2, LOW);
    }

    if (ReceivedMessage[0] == 100){
      // Both Motors Running Reverse Fast
      
      Serial.println("Reverse");
      Serial.print("Batt Percent: "); Serial.println(lc.cellPercent(), 1);
      batterycheck(lc.cellPercent());
      digitalWrite(Motor1P1, LOW);
      digitalWrite(Motor1P2, HIGH);
      digitalWrite(Motor2P1, LOW);
      digitalWrite(Motor2P2, HIGH);
      analogWrite(Motor1P2,255);
      analogWrite(Motor2P2,255);
    }
    
    if (ReceivedMessage[0] == 011) {
      // Both Motors Running Reverse Slower

      Serial.println("Reverse Slow");
      Serial.print("Batt Percent: "); Serial.println(lc.cellPercent(), 1);
      analogWrite(Motor1P2,125);
      analogWrite(Motor2P2,125);
    }

    if (ReceivedMessage[0] == 101){
      // TURN LEFT
      
      Serial.println("TURN LEFT");
      Serial.print("Batt Percent: "); Serial.println(lc.cellPercent(), 1);
      batterycheck(lc.cellPercent());
      digitalWrite(Motor1P1, LOW);
      digitalWrite(Motor1P2, HIGH);
      digitalWrite(Motor2P1, HIGH);
      digitalWrite(Motor2P2, LOW);
      analogWrite(Motor1P2,255);
      analogWrite(Motor2P1,255);
    }

    if (ReceivedMessage[0] == 110){
      // TURN RIGHT
      
      Serial.println("TURN RIGHT");
      Serial.print("Batt Percent: "); Serial.println(lc.cellPercent(), 1);
      batterycheck(lc.cellPercent());
      digitalWrite(Motor1P1, HIGH);
      digitalWrite(Motor1P2, LOW);
      digitalWrite(Motor2P1, LOW);
      digitalWrite(Motor2P2, HIGH);
      analogWrite(Motor1P1,255);
      analogWrite(Motor2P2,255);
    }


  }
}

void batterycheck(float charge) {
  // Green LED if above 50%
  // Yellow LED if between 50 and 10%
  // Red LED if below 10%
  if(charge > 50.0) {
    digitalWrite(Full,1);
    digitalWrite(Half,0);
    digitalWrite(Charge,0);
  } else if(charge > 10.0) {
    digitalWrite(Full,0);
    digitalWrite(Half,1);
    digitalWrite(Charge,0);
  } else  {
    digitalWrite(Full,0);
    digitalWrite(Half,0);
    digitalWrite(Charge,1);
  }
}
