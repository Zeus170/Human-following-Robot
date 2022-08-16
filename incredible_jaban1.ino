//vars
int minDist = 10000;
int posFlag;
int travelTime;

//constants
const int BOspeed = 100;


//ultrasonic sensor
const int echo = 2;
const int trig = 3;

//left tire
const int motor1Clk = 10;
const int motor1AntiClk = 11;


//right tire
const int motor2Clk = 9;
const int motor2AntiClk = 6;

#include <Servo.h>

Servo servo;



void setup(){
  Serial.begin(9600);
  servo.attach(2);
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  servo.write(90);
  
  int ang = scout();
  align(ang);
  
  
}
  
void loop(){
  
  
  
}

int scout(){
  for( int pos = 90; pos <= 180; pos++){

    servo.write(pos);
    delay(15);
    digitalWrite(trig, LOW);
    
    
    delayMicroseconds(2);
  
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
  
    digitalWrite(trig, LOW);
  
  
    duration = pulseIn(echo, HIGH);
  
    distance = duration * 0.034 / 2;
    
    minDist = min(minDist, distance);
    
    if(distance == minDist){
      posFlag = pos;
    }
    
    
  }

  for(int pos = 180; pos >=0; pos--){
    servo.write(pos);
    delay(15);
    
    servo.write(pos);
    delay(15);
    digitalWrite(trig, LOW);
    
    
    delayMicroseconds(2);
  
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
  
    digitalWrite(trig, LOW);
  
  
    duration = pulseIn(echo, HIGH);
  
    distance = duration * 0.034 / 2;
    
    minDist = min(minDist, distance);
    
    if(distance == minDist && (minDist< ){
      posFlag = pos;
    }
    
    
  }
  
  servo.write(90);
  delay(1000);
  
  return posFlag;
  
}

void align(int angle){
  
  if(angle>90){
  
  digitalWrite(motor1Clk, HIGH);
  digitalWrite(motor1AntiClk, LOW);
  digitalWrite(motor2Clk, LOW);
  digitalWrite(motor2AntiClk, HIGH);
  delay(2000);
    
  }
  
  else if( angle <90){
  digitalWrite(motor1Clk, HIGH);
  digitalWrite(motor1AntiClk, LOW);
  digitalWrite(motor2Clk, LOW);
  digitalWrite(motor2AntiClk, HIGH);
  delay(2000);
  }
  
  else{
    moveFwd(minDistance);
    
  }

  
  void moveFwd(int odo){
    
    travelTime = odo/BOspeed;
    
    digitalWrite(motor1Clk, HIGH);
    digitalWrite(motor1AntiClk, LOW);
    digitalWrite(motor2Clk, HIGH);
    digitalWrite(motor2AntiClk, LOW);
    delay(2000);
    
    sense();
    
    
  
  }
  
  void sense(){
    
    
  
  
  }
  
  void moveBkwd(distance){
    digitalWrite(motor1Clk, LOW);
    digitalWrite(motor1AntiClk, HIGH);
    digitalWrite(motor2Clk, LOW);
    digitalWrite(motor2AntiClk, HIGH);
    delay(2000);
    
    sense()
}  
  
  