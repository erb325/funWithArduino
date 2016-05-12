//sensor value holds the value of the photocell
int sensorValue;
int sensorHigh = 0;
int sensorLow = 1023;

// LEDPin 
const int ledPin = 8;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  while (millis() < 5000) {
    sensorValue = analogRead(A0);
    if(sensorValue > sensorHigh){
      sensorHigh = sensorValue;
    } 
    if (sensorValue < sensorLow){
      sensorLow = sensorValue; 
    }
  }
  digitalWrite(ledPin, LOW);
}

void loop() {
  //read the input from A0 and store it in a variable
  sensorValue = analogRead(A0);

  // map the sensor values to a wide range of pitches
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);

  // play the tone for 20 ms on pin 8
  tone(8, pitch, 20);

  // wait for a moment
  delay(10);

}
