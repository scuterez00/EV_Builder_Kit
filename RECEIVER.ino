#include "Adafruit_LC709203F.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <LiquidCrystal.h>

int ReceivedMessage[1] = {000};
RF24 radio(10, 2);
const byte address[6] = "00001";

LiquidCrystal lcd(A0, 9, A3, A2, A1, 8);

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
  
  lcd.begin(16, 2);
  lcd.print("Battery Power:");
  
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
  pinMode(Full,OUTPUT);
  pinMode(Half,OUTPUT);
  pinMode(Charge,OUTPUT);
}

void loop() {

//Sees if there is radio available to receive information
  while (radio.available()) {

    radio.read(ReceivedMessage, 1);

// Obtains 3-bit message to see what input the controller sent to change the current through the motors

    if (ReceivedMessage[0] == 001) {
      // Both Motors Running Forward Fast
      
      Serial.println("Forward");
      Serial.print("Batt Percent: "); Serial.println(lc.cellPercent(), 1);
      batterycheck(lc.cellPercent());
      lcd.setCursor(0, 1);
      lcd.print(lc.cellPercent(), 1);
      digitalWrite(Motor1P1, HIGH);
      digitalWrite(Motor1P2, LOW);
      digitalWrite(Motor2P1, HIGH);
      digitalWrite(Motor2P2, LOW);
      analogWrite(Motor1P1,255);
      analogWrite(Motor2P1,255);

      transmitter(address,lc.cellPercent(), ReceivedMessage[0]);
    }
    
    if (ReceivedMessage[0] == 010) {
      // Both Motors Running Forward Slower

      Serial.println("Forward Slow");
      Serial.print("Batt Percent: "); Serial.println(lc.cellPercent(), 1);
      lcd.setCursor(0, 1);
      lcd.print(lc.cellPercent(), 1);
      analogWrite(Motor1P1,125);
      analogWrite(Motor2P1,125);

      transmitter(address,lc.cellPercent(), ReceivedMessage[0]);
    }
    
    if (ReceivedMessage[0] == 000) {
      // Both Motors Off
      
      Serial.println("Off");
      Serial.print("Batt Percent: "); Serial.println(lc.cellPercent(), 1);
      batterycheck(lc.cellPercent());
      lcd.setCursor(0, 1);
      lcd.print(lc.cellPercent(), 1);
      digitalWrite(Motor1P1, LOW);
      digitalWrite(Motor1P2, LOW);
      digitalWrite(Motor2P1, LOW);
      digitalWrite(Motor2P2, LOW);

      transmitter(address,lc.cellPercent(), ReceivedMessage[0]);
    }

    if (ReceivedMessage[0] == 100){
      // Both Motors Running Reverse Fast
      
      Serial.println("Reverse");
      Serial.print("Batt Percent: "); Serial.println(lc.cellPercent(), 1);
      batterycheck(lc.cellPercent());
      lcd.setCursor(0, 1);
      lcd.print(lc.cellPercent(), 1);
      digitalWrite(Motor1P1, LOW);
      digitalWrite(Motor1P2, HIGH);
      digitalWrite(Motor2P1, LOW);
      digitalWrite(Motor2P2, HIGH);
      analogWrite(Motor1P2,255);
      analogWrite(Motor2P2,255);

      transmitter(address,lc.cellPercent(), ReceivedMessage[0]);
    }
    
    if (ReceivedMessage[0] == 011) {
      // Both Motors Running Reverse Slower

      Serial.println("Reverse Slow");
      Serial.print("Batt Percent: "); Serial.println(lc.cellPercent(), 1);
      lcd.setCursor(0, 1);
      lcd.print(lc.cellPercent(), 1);
      analogWrite(Motor1P2,125);
      analogWrite(Motor2P2,125);

      transmitter(address,lc.cellPercent(), ReceivedMessage[0]);
    }

    if (ReceivedMessage[0] == 101){
      // TURN LEFT
      
      Serial.println("TURN LEFT");
      Serial.print("Batt Percent: "); Serial.println(lc.cellPercent(), 1);
      batterycheck(lc.cellPercent());
      lcd.setCursor(0, 1);
      lcd.print(lc.cellPercent(), 1);
      digitalWrite(Motor1P1, LOW);
      digitalWrite(Motor1P2, HIGH);
      digitalWrite(Motor2P1, HIGH);
      digitalWrite(Motor2P2, LOW);
      analogWrite(Motor1P2,255);
      analogWrite(Motor2P1,255);

      transmitter(address,lc.cellPercent(), ReceivedMessage[0]);
    }

    if (ReceivedMessage[0] == 110){
      // TURN RIGHT
      
      Serial.println("TURN RIGHT");
      Serial.print("Batt Percent: "); Serial.println(lc.cellPercent(), 1);
      batterycheck(lc.cellPercent());
      lcd.setCursor(0, 1);
      lcd.print(lc.cellPercent(), 1);
      digitalWrite(Motor1P1, HIGH);
      digitalWrite(Motor1P2, LOW);
      digitalWrite(Motor2P1, LOW);
      digitalWrite(Motor2P2, HIGH);
      analogWrite(Motor1P1,255);
      analogWrite(Motor2P2,255);

      transmitter(address,lc.cellPercent(), ReceivedMessage[0]);
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

void transmitter(const byte stuff, float batt, int msg[0]) {

// Switches receiving to transmit to send the vehicle battery life

  char battery[8] = "";
  
  if (msg[0] == 111) {
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
