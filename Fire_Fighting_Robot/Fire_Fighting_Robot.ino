#include <AFMotor.h>
#include <Servo.h>  

Servo myservo;
 
int pos = 0; 


int Left = A1;     // left sensor
int Right = A0;   // right sensor
int Forward = A2;   //front sensor
int RelayPin = A4; //relay


AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);


int trash = 200;
int Speeed = 200;

void setup() {
  Serial.begin(9600);
  pinMode(Left, INPUT);
  pinMode(Right, INPUT);
  pinMode(Forward, INPUT);
  pinMode(RelayPin, OUTPUT);
  myservo.attach(10);
  myservo.write(90); 

}

void loop() {
  start();
}

void start()
{
  if ((analogRead(Forward) <= trash) && (analogRead(Left) <= trash) && (analogRead(Right) <= trash))
  {
    forward();
  }

  else if (analogRead(Forward) <= trash)
  {
    forward();
    Serial.println("FORWARD");
  }
  else if (analogRead(Left) <= trash)
  {
    left();
    Serial.println("LEFT");
  }

  else if (analogRead(Right) <= trash)
  {
    right();
    Serial.println("RIGHT");
  }
  else {
    stop();
  }
}


void forward()
{
  motor1.setSpeed(Speeed);
  motor1.run(FORWARD);
  motor2.setSpeed(Speeed);
  motor2.run(FORWARD);
  motor3.setSpeed(Speeed);
  motor3.run(FORWARD);
  motor4.setSpeed(Speeed);
  motor4.run(FORWARD);
  delay(300);

  digitalWrite(RelayPin , HIGH);
  delay(500);
  for(pos = 0; pos <= 180; pos += 1) 
  {
    myservo.write(pos);
    delay(15);
  }
  for(pos = 180; pos>=0; pos-=1)
  {
    myservo.write(pos);
    delay(15);
  }
  digitalWrite(RelayPin , LOW);
  delay(10);
  
}
void left()
{
  motor1.setSpeed(Speeed);
  motor1.run(FORWARD);
  motor2.setSpeed(Speeed);
  motor2.run(BACKWARD);
  motor3.setSpeed(Speeed);
  motor3.run(BACKWARD);
  motor4.setSpeed(Speeed);
  motor4.run(FORWARD);
}

void right()
{
  motor1.setSpeed(Speeed);
  motor1.run(BACKWARD);
  motor2.setSpeed(Speeed);
  motor2.run(FORWARD);
  motor3.setSpeed(Speeed);
  motor3.run(FORWARD);
  motor4.setSpeed(Speeed);
  motor4.run(BACKWARD);
}
void stop()
{
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}
