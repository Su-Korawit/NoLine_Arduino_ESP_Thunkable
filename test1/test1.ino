#define ENA 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 10
#define ENB 11

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  
  Serial.begin(9600);
}

void loop() {
  forwardRobot();
  delay(3000);
  backwardRobot();
  delay(3000);
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
