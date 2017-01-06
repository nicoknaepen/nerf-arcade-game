int arrObjects[] = {8, 9, 10, 11, 12};
int arrLeds[] = {2, 3, 4, 5, 6};
int arrHits[] ={0, 0, 0, 0, 0};
int i;
int currentHit;
int maxObjects = 5;

// Setup the application.
void setup() {
  initPinModes();
  reset(true);
}

// Constant loop within the application.
void loop() {
  for (i = 0; i < 5; i = i + 1) {
    // Verify if the object is hit.
    objectHitVerification(i);
  }
}

// Reset the vars, tones and leds.
void reset(bool init) {
  initVars(init);
  initTones(init);
  initLeds(init);
}

// Initialize all the pinModes by a pre-defined set of arrays.
void initPinModes() {
  for (i = 0; i < 5; i = i + 1) {
    // Initialize pinMode for leds.
    pinMode(arrLeds[i], OUTPUT);
    // Initialize pinMode for objects to hit.
    pinMode(arrObjects[i], INPUT);
  }
  // Initialize pinMode for the buzzer.
  pinMode(7, OUTPUT);
  pinMode(1, OUTPUT);
}

// Initialize variables.
void initVars(bool init) {
  currentHit = -1;
}

// Read the hitstate and highlight the object if hit.
void objectHitVerification(int i) {
  int hitState = digitalRead(arrObjects[i]);
  if (hitState == HIGH) {
    if (arrHits[i] == 0) {
      objectHit(i);
    }
  }
}

// Highlight the object cause it is hit.
int objectHit(int i) {
  objectHitTone(500,750);
  currentHit = currentHit + 1;
  digitalWrite(arrLeds[currentHit], HIGH);
  arrHits[i] = 1;
  verifyAllObjectsAreHit();
}

// Verify if all objects are hit and if so, then reset.
void verifyAllObjectsAreHit() {
  if (currentHit == (maxObjects - 1)) {
    currentHit = -1;
    reset(false);
  }
}

void objectHitTone(int tone1, int tone2){
  digitalWrite(1, HIGH);
  tone(7, tone1, 100);
  delay(110);
  tone(7, tone1, 100);
  delay(110);
  tone(7, tone2, 250);
  delay(110);
  digitalWrite(1, LOW);
}

void initTones(bool init) {
  if (not init) {
    objectHitTone(500,750);
    objectHitTone(500,1000);
    objectHitTone(1000,1250);
    objectHitTone(1250,1500);
    objectHitTone(2000,2000);
  }
  else {
    objectHitTone(500,750);
    objectHitTone(500,1000);
  }
}

void initLeds(bool init) {
  for (i = 0; i < 5; i = i + 1) {
    digitalWrite(arrLeds[i], HIGH);
    delay(40);
    arrHits[i] = 0;
    digitalWrite(arrLeds[i], LOW); 
  }
  digitalWrite(1, HIGH);
  delay(40);
  digitalWrite(1, LOW);
}

