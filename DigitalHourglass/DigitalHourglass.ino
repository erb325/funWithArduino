// Global variables 
const int switchPin = 8;
unsigned long previousTime = 0; // this will hold the time the LED was changed
int switchState = 0; // needed to compare the switches postion from one loop to the next
int previousSwitchState = 0;
int led = 2; // this is the first pin and will be used when we need to turn on the next pin 
long interval = 1000; // the interval netween each LED changing

void setup() {
  for (int i = 2; i < 7; i++){ // declare pins 2-7 as output 
    pinMode(i, OUTPUT);
  }
   pinMode(switchPin, INPUT); // declare switchPin as input 

}

void loop() {
  unsigned long currentTime = millis(); // the amount of time the arduino has been running

  if (currentTime - previousTime > interval) { 
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    led++;

    if (led == 7){
      
    }
  }

  if (switchState != previousSwitchState) {
    for (int x = 2; x < 8; x++){
      digitalWrite(x, LOW);
    }
    led = 2;
    previousTime = currentTime;
  }
  previousSwitchState = switchState; 
}
