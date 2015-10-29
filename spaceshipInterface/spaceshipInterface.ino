/* Spaceship Interface 
 *  Cool Control Panel with a switch and Light
 *  that turn on when you press the switch
 * You can decide whether the lights "engage hyperdrive"
 * or "Fire the lasers!" a green LED will be on 
 * until press a button when the arduino gets a signal 
 * from the button the green light will go off and the other lights 
 * will start blinking. 
 */
 
int switchState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);

  if (switchState == LOW){      //if button is not pressed 
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } else {                      // else toggle red 
    digitalWrite (3, LOW);
    digitalWrite (4, LOW);
    digitalWrite (5, HIGH);

    delay(250);
    digitalWrite (4, HIGH);
    digitalWrite (5, LOW);
    delay(250);

    
  }

}
