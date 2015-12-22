// Mood Cue: learn how to use the servo motor
#include <Servo.h> // needed to use the servo motor 

// global variables 
Servo myServo;
int const potPin = A0; // potentiometer input pin 
int potValue;
int angle ;

void setup() {
  myServo.attach(9); // set up the servo 

  Serial.begin(9600);
}

void loop() {
  potValue = analogRead(potPin);

  Serial.print("PotVal: ");
  Serial.print(potValue);
  Serial.print(" \n");
  
  angle = map(potValue, 0 , 1023, 0 ,179); // take the number from potPin and mao it to a number between 0-179
  Serial.print("Angle: " );
  Serial.print(angle);
  Serial.print(" \n");
  myServo.write(angle); 
  delay(15);
  

}
