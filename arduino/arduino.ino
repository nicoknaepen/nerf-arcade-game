int hitState = 0;
int led2Active = 0;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  pinMode(7, OUTPUT);
  initTones();
  initLeds();
}

void loop() {
  objectHitVerification(8, 2);
}

int objectHitVerification(int object, int led) {
  hitState = digitalRead(object);

  if (hitState == HIGH) {
    if (led2Active == 0) {
      objectHit(led);
    }
  }
}

int objectHit(int led) {
  objectHitTone(500,750);  
  digitalWrite(2, HIGH);
  led2Active = 1;  
}

int objectHitTone(int tone1, int tone2){
  tone(7, tone1, 100);
  delay(120);
  tone(7, tone1, 100);
  delay(120);
  tone(7, tone2, 250);
  delay(120);
}

void initTones() {
  objectHitTone(500,750);  
  objectHitTone(500,1000);  
}

void initLeds() {
  digitalWrite(2, HIGH);
  delay(120);
  digitalWrite(2, LOW); 
}

