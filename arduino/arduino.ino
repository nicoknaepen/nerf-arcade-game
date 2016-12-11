int hitState = 0;
int arrObjects[] = {8, 9, 10, 11, 12};
int arrLeds[] = {2, 3, 4, 5, 6};
int arrHitObjects[] = {};
int i;

void setup() {
  // Initialize pinMode for leds and buttons/objects to hit.
  for (i = 0; i < 5; i = i + 1) {
    pinMode(arrLeds[i], OUTPUT);
    pinMode(arrObjects[i], INPUT);
    arrHitObjects[i] = 0;
  }
  Serial.begin(9600);
  Serial.print("Hello again");
  // Initialize pinMode for the buzzer.
  pinMode(7, OUTPUT);
  // Test the tones and the leds.
  testTones();
  testLeds();
}

void loop() {
  for (i = 0; i < 5; i = i + 1) {
    objectHitVerification(i);
  }
}

int objectHitVerification(int i) {
  hitState = digitalRead(arrObjects[i]);
  if (hitState == HIGH) {
    if (arrHitObjects[i] == 0) {
      objectHit(i);
      arrHitObjects[i] = 1;
    }
  }
}

int objectHit(int i) {
  objectHitTone(500,750);  
  digitalWrite(arrLeds[i], HIGH);
}

int objectHitTone(int tone1, int tone2){
  tone(7, tone1, 100);
  delay(110);
  tone(7, tone1, 100);
  delay(110);
  tone(7, tone2, 250);
  delay(110);
}

void testTones() {
  objectHitTone(500,750);  
  objectHitTone(500,1000);  
}

void testLeds() {
  for (i = 0; i < 5; i = i + 1) {
    digitalWrite(arrLeds[i], HIGH);
    delay(60);
    digitalWrite(arrLeds[i], LOW); 
  }
}

