int buttonState = 0;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  pinMode(8, INPUT);
  digitalWrite(2, LOW);
}

void loop() {
  buttonState = digitalRead(8);
 
  if (buttonState == HIGH) {
    digitalWrite(2, HIGH);
  }
}
