#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

RF24 radio(9, 8);
const byte address[6] = "00001";
int yPosition_1 = 0;
int yPosition_2 = 0;

int SentMessage[1] = {000};

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  
  radio.begin();

  radio.openWritingPipe(address);

  radio.stopListening();
}

void loop() {

  yPosition_1 = analogRead(A0);
  yPosition_2 = analogRead(A1);

  if ((yPosition_1 > 500) && (yPosition_1 < 520)) {
    if ((yPosition_2 > 500) && (yPosition_2 < 520)) {
      SentMessage[0] = 000;
      radio.write(SentMessage, 1);
    }
  } 

  if ((yPosition_1 < 100) && (yPosition_2 < 100)) {
    SentMessage[0] = 001;
    radio.write(SentMessage, 1);
  }

  if ((yPosition_1 < 500) && (yPosition_1 > 100)) {
    if ((yPosition_2 < 500) && (yPosition_2 > 100)) {
      SentMessage[0] = 010;
      radio.write(SentMessage, 1);
    }
  }

  if ((yPosition_1 > 1000) && (yPosition_2 > 1000)) {
    SentMessage[0] = 100;
    radio.write(SentMessage, 1);
  }

  if ((yPosition_1 > 520) && (yPosition_1 < 1000)) {
    if ((yPosition_2 > 520) && (yPosition_2 < 1000)) {
      SentMessage[0] = 011;
      radio.write(SentMessage, 1);
    }
  }

  if ((yPosition_1 < 500) && (yPosition_2 > 520)) {
    SentMessage[0] = 110;
    radio.write(SentMessage, 1);
  }

  if ((yPosition_1 > 520) && (yPosition_2 < 500)) {
    SentMessage[0] = 101;
    radio.write(SentMessage, 1);
  }

  Serial.println(yPosition_1);
  Serial.println("\t");
  Serial.println(yPosition_2);

  /*
  
  if ((yPosition_1 > 500) && (yPosition_1 < 520)) {
    if ((yPosition_2 > 500) && (yPosition_2 < 520)) {
      SentMessage[0] = 000;
      radio.write(SentMessage, 1);
    }
  } 
  if ((yPosition_1 < 300) && (yPosition_2 < 300)) {
    SentMessage[0] = 001;
    radio.write(SentMessage, 1);
  } 
  if ((yPosition_1 < 500) && (yPosition_1 > 200)) {
    if ((yPosition_2 < 500) && (yPosition_2 > 200)) {
      SentMessage[0] = 010;
      radio.write(SentMessage, 1);
    }
  }
  if ((yPosition_1 > 520) && (yPosition_1 < 800)) {
    if ((yPosition_2 > 520) && (yPosition_2 < 800)) {
      SentMessage[0] = 011;
      radio.write(SentMessage, 1);
    }
  }
  if ((yPosition_1 > 800) && (yPosition_2 > 800)) {
    SentMessage[0] = 100;
    radio.write(SentMessage, 1);
  }
  if ((yPosition_1 < 500) && (yPosition_2 > 520)) {
    SentMessage[0] = 101;
    radio.write(SentMessage, 1);
  }
  if ((yPosition_1 > 520) && (yPosition_2 < 500)) {
    SentMessage[0] = 110;
    radio.write(SentMessage, 1);
  }

  */
  

}
