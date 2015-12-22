// Keyboard instrument 

//Global Variables
int notes[] = {262,294, 330,349};

void setup() {
  Serial.begin(9600);

}

void loop() {
  int keyVal = analogRead(A0);
  Serial.print(keyVal);
   Serial.print("\n");

  if (keyVal >= 1001 && keyVal <= 1023){
    tone(8,notes[0]);
  } else if (keyVal>= 990 && keyVal <= 1000) {
    tone(8,notes[1]);
  } else if (keyVal>= 505 && keyVal <= 989) {
    tone(8,notes[2]);
  }else if (keyVal>= 5 && keyVal <= 504) {
    tone(8,notes[3]);
  } else {
    noTone(8);
  }

}
