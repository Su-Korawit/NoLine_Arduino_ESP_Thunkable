#define ENA 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 10
#define ENB 11

#include <SoftwareSerial.h>
SoftwareSerial Uno(0, 1); // RX | TX

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  
  Serial.begin(9600);
  Uno.begin(9600);
}

void loop() {
  while (Uno.available() > 0)
  {
    if (Uno.read() == '\n') {
      int val = Uno.parseInt();
      Serial.println(val);
      
      switch(val) {
        case 5:
          forwardRobot();
          break;
        case 1:
          backwardRobot();
          break;
        case 2:
          leftRobot();
          break;
        case 3:
          rightRobot();
          break;
        case 4:
          stopRobot();
          break;  
      }
    }
  }
}

void forwardRobot() {
  Serial.println("Forward");
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void backwardRobot() {
  Serial.println("Backward");
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void leftRobot() {
  Serial.println("Turn Left");
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void rightRobot() {
  Serial.println("Turn Rigth");
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopRobot() {
  Serial.println("Stop");
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
