// RGB LED

//Setting up the color pins
int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup() {
  //set up pins as output
  pinMode (redPin, OUTPUT);
  pinMode (greenPin, OUTPUT);
  pinMode (bluePin, OUTPUT);

}

void loop() {
  setColor(255, 0, 0); // red
  delay(5000);
  setColor(0, 255, 0); // green
  delay(5000);
  setColor(0, 0, 255); // blue
  delay(5000);
  setColor(255, 255, 0);  // orange 
  delay(5000);  
  setColor(80, 0, 80);  // purple
  delay(5000);
  setColor(0, 255, 255);  // aqua -- looks blue 
  delay(5000);
  setColor(255, 192, 203);  // pink
  delay(5000);
  setColor(0, 0, 0);  // black -- turns off the light
  delay(5000);
  setColor(188, 143, 143);  // rosybrown -- looks pink
  delay(5000);
}
void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
