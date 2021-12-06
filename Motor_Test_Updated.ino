//Defining LEDs that will light up to signify what direction the motors should be running
#define M1forward 7
#define M1reverse 8
#define M2forward 9
#define M2reverse 10

void setup() {
  // put your setup code here, to run once:
  pinMode(M1forward,OUTPUT);
  pinMode(M1reverse,OUTPUT);
  pinMode(M2forward,OUTPUT);
  pinMode(M2forward,OUTPUT);  
}

void loop() {
  // Both Motors Running Forward Fast
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  analogWrite(3,255);
  analogWrite(5,255);
  // During this time leds are on
  digitalWrite(M1forward,1);
  digitalWrite(M1reverse,0);
  digitalWrite(M2forward,1);
  digitalWrite(M2reverse,0);
  delay(5000);

  // Both Motors Running Forward Slower
  analogWrite(3,150);
  analogWrite(5,150);
  //During this time flash leds
  for(int i = 0; i<10; i++) {
    if(i%2 == 0) {
      digitalWrite(M1forward,1);
      digitalWrite(M1reverse,0);
      digitalWrite(M2forward,1);
      digitalWrite(M2reverse,0);
    } else {
      digitalWrite(M1forward,0);
      digitalWrite(M1reverse,0);
      digitalWrite(M2forward,0);
      digitalWrite(M2reverse,0);
    }
    delay(500);
  }
  
  // Both Motors Off
  digitalWrite(M1forward,0);
  digitalWrite(M1reverse,0);
  digitalWrite(M2forward,0);
  digitalWrite(M2reverse,0);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  delay(5000);
  
  // Both Motors Running Reverse Fast
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  analogWrite(4,255);
  analogWrite(6,255);
  // Reverse LEDS on
  digitalWrite(M1forward,0);
  digitalWrite(M1reverse,1);
  digitalWrite(M2forward,0);
  digitalWrite(M2reverse,1);
  delay(5000);
  
  // Both Motors Running Forward Slower
  analogWrite(4,150);
  analogWrite(6,150);
  //During this time flash leds
  for(int i = 0; i<10; i++) {
    if(i%2 == 0) {
      digitalWrite(M1forward,0);
      digitalWrite(M1reverse,1);
      digitalWrite(M2forward,0);
      digitalWrite(M2reverse,1);
    } else {
      digitalWrite(M1forward,0);
      digitalWrite(M1reverse,0);
      digitalWrite(M2forward,0);
      digitalWrite(M2reverse,0);
    }
    delay(500);
  }  
  
}
