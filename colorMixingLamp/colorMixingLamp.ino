const int greenLEDPin = 9;    
const int redLEDPin = 11;     
const int blueLEDPin = 10;    

const int redSensorPin = A0;  
const int greenSensorPin = A1;   
const int blueSensorPin = A2;

int redValue = 0; 
int greenValue = 0; 
int blueValue = 0; 

int redSensorValue = 0; 
int greenSensorValue = 0; 
int blueSensorValue = 0; 


void setup() {
  Serial.begin(9600);

  pinMode (redLEDPin, OUTPUT);
  pinMode (greenLEDPin, OUTPUT);
  pinMode (blueLEDPin, OUTPUT);

}

void loop() {
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);

  Serial.print("Raw sensro values \t Red: ");
  Serial.print(redSensorValue);
  Serial.print("\tGreen: ");
  Serial.print(greenSensorValue);
  Serial.print("\tblue: ");
  Serial.print(blueSensorValue);
  Serial.print("\n");

  redValue = redSensorValue/4;
  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4;

  Serial.print("Mapped sensor values \t Red: ");
  Serial.print(redValue);
  Serial.print("\tGreen: ");
  Serial.print(greenValue);
  Serial.print("\tblue: ");
  Serial.print(blueValue);
  Serial.print("\n");

  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);
}