#include "Adafruit_LC709203F.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int ReceivedMessage[1] = {000};
RF24 radio(10, 2);
const byte address[6] = "00100";
char POWER[8] = "";

//Defining the State of Charge Board
Adafruit_LC709203F lc;
//Defining LEDs that will light up to signify battery power
#define Motor1P1 3
#define Motor1P2 4
#define Motor2P2 5
#define Motor2P1 6
#define On 8

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
  lc.setPackSize(LC709203F_APA_500MAH);
  lcd.setCursor(0, 1);
  lcd.print(lc.cellPercent(), 1);

  //Set Output Mode for the Pins
  pinMode(Motor1P1, OUTPUT);
  pinMode(Motor1P2, OUTPUT);
  pinMode(Motor2P1, OUTPUT);
  pinMode(Motor2P2, OUTPUT);
  pinMode(On,OUTPUT);
}

void loop() {
  while (radio.available()) {
    // If Radio Pipe Open = Controller Communicating
    digitalWrite(On, HIGH);
    radio.read(ReceivedMessage, 1);

    if (ReceivedMessage[0] == 001) {
      // Both Motors Running Forward Fast
      digitalWrite(Motor1P1, HIGH);
      digitalWrite(Motor1P2, LOW);
      digitalWrite(Motor2P1, HIGH);
      digitalWrite(Motor2P2, LOW);
      analogWrite(Motor1P1,255);
      analogWrite(Motor2P1,255);
    }
    
    if (ReceivedMessage[0] == 010) {
      // Both Motors Running Forward Slower
      digitalWrite(Motor1P1, HIGH);
      digitalWrite(Motor1P2, LOW);
      digitalWrite(Motor2P1, HIGH);
      digitalWrite(Motor2P2, LOW);
      analogWrite(Motor1P1,125);
      analogWrite(Motor2P1,125);
    }
    
    if (ReceivedMessage[0] == 000) {
      // Both Motors Off
      digitalWrite(Motor1P1, LOW);
      digitalWrite(Motor1P2, LOW);
      digitalWrite(Motor2P1, LOW);
      digitalWrite(Motor2P2, LOW);
    }

    if (ReceivedMessage[0] == 100){
      // Both Motors Running Reverse Fast
      digitalWrite(Motor1P1, LOW);
      digitalWrite(Motor1P2, HIGH);
      digitalWrite(Motor2P1, LOW);
      digitalWrite(Motor2P2, HIGH);
      analogWrite(Motor1P2,255);
      analogWrite(Motor2P2,255);
    }
    
    if (ReceivedMessage[0] == 011) {
      // Both Motors Running Reverse Slower
      digitalWrite(Motor1P1, LOW);
      digitalWrite(Motor1P2, HIGH);
      digitalWrite(Motor2P1, LOW);
      digitalWrite(Motor2P2, HIGH);
      analogWrite(Motor1P2,125);
      analogWrite(Motor2P2,125);
    }

    if (ReceivedMessage[0] == 101){
      // TURN LEFT
      digitalWrite(Motor1P1, LOW);
      digitalWrite(Motor1P2, HIGH);
      digitalWrite(Motor2P1, HIGH);
      digitalWrite(Motor2P2, LOW);
      analogWrite(Motor1P2,255);
      analogWrite(Motor2P1,255);
    }

    if (ReceivedMessage[0] == 110){
      // TURN RIGHT
      digitalWrite(Motor1P1, HIGH);
      digitalWrite(Motor1P2, LOW);
      digitalWrite(Motor2P1, LOW);
      digitalWrite(Motor2P2, HIGH);
      analogWrite(Motor1P1,255);
      analogWrite(Motor2P2,255);
    }

    if (ReceivedMessage[0] == 111) {
      radio.begin();
      radio.openWritingPipe(address);
      radio.stopListening();

      dtostrf(lc.cellPercent(), 6, 2, POWER);
      radio.write(&POWER, sizeof(POWER));

      radio.begin();
      radio.openReadingPipe(0, address);
      radio.startListening();
  }

  }
  digitalWrite(On, LOW);
}

void transmitter(const byte stuff, float batt, int msg[0]) {
  char battery[8] = "";
  
  if (msg[0] == 111) {
    Serial.println("RECEIVED");
    radio.begin();
    radio.openWritingPipe(stuff);
    radio.stopListening();

    dtostrf(batt, 6, 2, battery);
    radio.write(&battery, sizeof(battery));

    radio.begin();
    radio.openReadingPipe(0, stuff);
    radio.startListening();
  }
  return;
}
