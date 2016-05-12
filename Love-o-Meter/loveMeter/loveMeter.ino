/* Love-o-meter
 *  Learn how to use the temperature sensor, 
 *  to read in analog data, and interpret the
 *  data.  
 */

const int sensorPin = A0;
const float baselineTemp = 23.0;

void setup() {
  
  /* Opens the connection between the Arduino and the computer 
   * to get the values from the Analog input
   * the argument 9600 is the speed, 9600 bits per second
   */
  Serial.begin(9600); // open a serial port 

  for (int pinNumber = 2; pinNumber < 5; pinNumber++){
    pinMode (pinNumber, OUTPUT);    // sets up pins to accept output
    digitalWrite (pinNumber, LOW);  // turn all the lights off 
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);  // get a reading from the temp pin 

  Serial.print("Sensor Value: ");         // print to the consol
  Serial.print(sensorVal);
  
  float voltage = (sensorVal/ 1024.0) * 5; //Convert the ADC Reading to voltage 

  Serial.print(", Volts: ");
  Serial.print(voltage);

  float temperature = (voltage - .5) * 100;

  Serial.print(", Degrees C: "); 
  Serial.print(temperature);
  Serial.print("\n");                     // carriage return  

  /* if baseline then all lights off 
   *  if 2 degrees above base temp light one light 
   *  if 4 degrees above base temp light 2 lights
   *  if 6 degrees or more than base temp light 3 lights
  */
  if (temperature < baselineTemp) {         
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 2 && temperature < baselineTemp + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 4 && temperature < baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  } 
  delay(1);
}
