#include <LiquidCrystal_I2C.h>
#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

RF24 radio(9, 8);
LiquidCrystal_I2C lcd(0x27, 20, 4);
const byte vehicle_1[6] = "00011";
const byte vehicle_2[6] = "00100";
const byte vehicle_3[6] = "00110";
byte vehicle[6] = "00000";
int yPosition_1 = 0;
int xPosition_2 = 0;
int Switch_1;
int Switch_2;
int Switch_3;
long timer = 0;
float miles_1 = 149.00;
float miles_2 = 149.00;
float miles_3 = 149.00;

int SentMessage[1] = {000};

void setup() {
  Serial.begin(19200);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(7, INPUT);
  lcd.begin();
  lcd.setCursor(0,0);
  lcd.print("Nissan Leaf S");
  lcd.setCursor(0,2);
  lcd.print("Miles: ");
//  lcd.setCursor(0,3);
//  lcd.print("Actual Battery:");
  
}

void loop() {
  yPosition_1 = analogRead(A0);
  xPosition_2 = analogRead(A1);
  Switch_1 = digitalRead(4);
  Switch_2 = digitalRead(7);
  Switch_3 = digitalRead(3);

  switch (Switch_1) {
    case 1:
      lcd.setCursor(0,0);
      lcd.print("Nissan Leaf S (1)");
      radio.begin();
      radio.openWritingPipe(vehicle_1);
      radio.stopListening();
      if ((timer % 10) == 0) {
      //  Serial.println(timer);
      //  switch_to_receiver(vehicle_1);
        miles_1 = miles_1 - 1;
      }
        lcd.setCursor(8,2);
        lcd.print(miles_1);
        while(miles_1 < 1) {
          miles_1 = 0;
          lcd.setCursor(6,2);
          lcd.print("NEEDS CHARGING");
          SentMessage[0] = 000;
          radio.write(SentMessage, 1);
          Serial.println(Switch_1);
          Switch_1 = digitalRead(4);
          if (Switch_1 != 1) {
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Nissan Leaf S");
            lcd.setCursor(0,2);
            lcd.print("Miles: ");
            break;
          }
        }
      //Serial.println("00011");
      break;
      
    case 0:
      break;
  }

  switch (Switch_2 == 1) {
    case 1:
      lcd.setCursor(0,0);
      lcd.print("Nissan Leaf S (2)");
      radio.begin();
      radio.openWritingPipe(vehicle_2);
      radio.stopListening();
      if ((timer % 500) == 0) {
      //  Serial.println(timer);
      //  switch_to_receiver(vehicle_2);
        miles_2 = miles_2 - 1;
      }
        lcd.setCursor(8,2);
        lcd.print(miles_2);
        while(miles_2 < 1) {
          miles_2 = 0;
          lcd.setCursor(6,2);
          lcd.print("NEEDS CHARGING");
          SentMessage[0] = 000;
          radio.write(SentMessage, 1);
          Serial.println(Switch_2);
          Switch_3 = digitalRead(2);
          if (Switch_2 != 1) {
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Nissan Leaf S");
            lcd.setCursor(0,2);
            lcd.print("Miles: ");
            break;
          }
        }
      //Serial.println("00100");
      break;

    case 0:
      break;
  }
  
  switch (Switch_3 == 1) {
    case 1:
      lcd.setCursor(0,0);
      lcd.print("Nissan Leaf S (3)");
      radio.begin();
      radio.openWritingPipe(vehicle_3);
      radio.stopListening();
      if ((timer % 250) == 0) {
      //  Serial.println(timer);
      //  switch_to_receiver(vehicle_3);
        miles_3 = miles_3 - 1;
      }
        lcd.setCursor(8,2);
        lcd.print(miles_3);
        while(miles_3 < 1) {
          miles_3 = 0;
          lcd.setCursor(6,2);
          lcd.print("NEEDS CHARGING");
          SentMessage[0] = 000;
          radio.write(SentMessage, 1);
          Serial.println(Switch_3);
          Switch_3 = digitalRead(3);
          if (Switch_3 != 1) {
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Nissan Leaf S");
            lcd.setCursor(0,2);
            lcd.print("Miles: ");
            break;
          }
        }
      //Serial.println("00110");
      break;

    case 0:
      break;
  }

///////////////////////////////////////////////////////////////////////////////////////////////////
// These are the coordiantes for the joysticks and depending the coordinates decides the input for the controller,
  yPosition_1 = analogRead(A0);
  xPosition_2 = analogRead(A1);

  if ((yPosition_1 > 500) && (yPosition_1 < 520)) {
    //No movement
    SentMessage[0] = 000;
    radio.write(SentMessage, 1);
  } 

  if (yPosition_1 < 100) {
    //Backwards
    SentMessage[0] = 001;
    radio.write(SentMessage, 1);
  }

  if ((yPosition_1 < 500) && (yPosition_1 > 100)) {
    //Slower backwards
    SentMessage[0] = 010;
    radio.write(SentMessage, 1);
  }

  if (yPosition_1 > 1000) {
    //Forward
    SentMessage[0] = 100;
    radio.write(SentMessage, 1);
  }

  if ((yPosition_1 > 520) && (yPosition_1 < 1000)) {
    //Slower Forwards
    SentMessage[0] = 011;
    radio.write(SentMessage, 1);
  }

  if (xPosition_2 > 750) {
    //Turn Right
    SentMessage[0] = 110;
    radio.write(SentMessage, 1);
  }

  if (xPosition_2 < 250) {
    //Turn Left
    SentMessage[0] = 101;
    radio.write(SentMessage, 1);
  }

  timer = timer + 1;  //Global timer for how many cycles the code goes through
  
}

/////////////////////////////////////////////////////////////////////////////////////////////////

float switch_to_receiver(const byte vehicle[6]) {

//This fuction is used to switch the transmitter from transmitting to receiving to optain the battery percentage and
//display it on the LCD
  
  SentMessage[0] = 111;
  char battery[8] = "";
  long int kill_switch = 0;
  float lcd_battery;
  
  radio.write(SentMessage, 1);

  radio.begin();
  radio.openReadingPipe(0, vehicle);
  radio.startListening();

  while (!radio.available()) {
    kill_switch = kill_switch+1;
    //Serial.println("ERROR");
    radio.read(&battery, sizeof(battery));
    if (kill_switch > 10) {
      break;
    }
  }

  radio.read(&battery, sizeof(battery));

  radio.begin();
  radio.openWritingPipe(vehicle);
  radio.stopListening();

  Serial.println(atof(battery));
  lcd_battery = atof(battery);

  lcd.setCursor(0,3);
  lcd.print("Actual Battery:");

  lcd_battery = lcd_battery - .671;

  lcd.setCursor(14,3);
  lcd.print(battery);
  lcd.print(" ");
  return atof(battery);

}
