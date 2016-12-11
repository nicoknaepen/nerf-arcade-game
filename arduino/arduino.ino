int buttonState = 0;
int led2Active = 0;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(2, LOW);
}

void loop() {
  buttonState = digitalRead(8);

  if (buttonState == HIGH) {
    digitalWrite(2, HIGH);
    if (led2Active == 0) {
      tone(7, 500, 100);
      delay(120);
      tone(7, 500, 100);
      delay(120);
      tone(7, 750, 250);
      led2Active = 1;
    }
  }
}
