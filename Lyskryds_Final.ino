const int buttonPin = 2; // Knap forbundet til 2
const int ResetbuttonPin = 4; // Knap forbundet til 4
const int redPin1 = 11;  // Rød LED 1
const int yelPin1 = 10;  // Gul LED 1
const int grnPin1 = 9;   // Grøn LED 1
const int redPin2 = 3;   // Rød LED 2
const int yelPin2 = 5;   // Gul LED 2
const int grnPin2 = 6;   // Grøn LED 2

// Timing-variabler
const unsigned long phaseDuration = 3000;        // Varighed for hver fase
const unsigned long shortPhaseDuration = 500;    // Kortere varighed for overgangen
const unsigned long semishortPhaseDuration = 800;    
bool sequenceStarted = false; // Flag til at indikere, om sekvensen er startet

void setup() {
  // Konfigurer pins med LED som output
  pinMode(redPin1, OUTPUT);
  pinMode(yelPin1, OUTPUT);
  pinMode(grnPin1, OUTPUT);

  pinMode(redPin2, OUTPUT);
  pinMode(yelPin2, OUTPUT);
  pinMode(grnPin2, OUTPUT);

  // Konfigurer knap-pins som input med pull-up modstand
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ResetbuttonPin, INPUT_PULLUP);

  ResetLED();
}

void loop() {
  // Check if the main button is pressed to start the sequence
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW && !sequenceStarted) {
    sequenceStarted = true; // Start the sequence
  }

  // Run the sequence if it is started
  if (sequenceStarted) {
    // Light set 1
    redLight1();
    delayWithResetCheck(semishortPhaseDuration);
    redYellowLight1();
    delayWithResetCheck(semishortPhaseDuration);
    greenLight1();
    delayWithResetCheck(phaseDuration);
    yellowLight1();
    delayWithResetCheck(semishortPhaseDuration);
    redLight1();

    // Light set 2
    redLight2();
    delayWithResetCheck(semishortPhaseDuration);
    redYellowLight2();
    delayWithResetCheck(semishortPhaseDuration);
    greenLight2();
    delayWithResetCheck(phaseDuration);
    yellowLight2();
    delayWithResetCheck(semishortPhaseDuration);
    redLight2();
  }
}

// Delay function with reset check
void delayWithResetCheck(unsigned long duration) {
  unsigned long start = millis();
  while (millis() - start < duration) {
    if (digitalRead(ResetbuttonPin) == LOW) {
      ResetLED();
      sequenceStarted = false;
      break;
    }
  }
}

// Forsklige kombinationer for de første lys
void redLight1() {
  digitalWrite(redPin1, HIGH);  // Tænd rød
  digitalWrite(yelPin1, LOW);   // Sluk gul
  digitalWrite(grnPin1, LOW);   // Sluk grøn
}

void redYellowLight1() {
  digitalWrite(redPin1, HIGH);
  digitalWrite(yelPin1, HIGH);
  digitalWrite(grnPin1, LOW);
}

void greenLight1() {
  digitalWrite(redPin1, LOW);
  digitalWrite(yelPin1, LOW);
  digitalWrite(grnPin1, HIGH);
}

void yellowLight1() {
  digitalWrite(redPin1, LOW);
  digitalWrite(yelPin1, HIGH);
  digitalWrite(grnPin1, LOW);
}

// Funktioner til at styre LED'er for lysesæt 2
void redLight2() {
  digitalWrite(redPin2, HIGH);
  digitalWrite(yelPin2, LOW);
  digitalWrite(grnPin2, LOW);
}

void redYellowLight2() {
  digitalWrite(redPin2, HIGH);
  digitalWrite(yelPin2, HIGH);
  digitalWrite(grnPin2, LOW);
}

void greenLight2() {
  digitalWrite(redPin2, LOW);
  digitalWrite(yelPin2, LOW);
  digitalWrite(grnPin2, HIGH);
}

void yellowLight2() {
  digitalWrite(redPin2, LOW);
  digitalWrite(yelPin2, HIGH);
  digitalWrite(grnPin2, LOW);
}

// Alle er slukket
void allLedsOff() {
  digitalWrite(redPin1, LOW);
  digitalWrite(yelPin1, LOW);
  digitalWrite(grnPin1, LOW);
  
  digitalWrite(redPin2, LOW);
  digitalWrite(yelPin2, LOW);
  digitalWrite(grnPin2, LOW);
}

void ResetLED() {
  digitalWrite(redPin1, HIGH);
  digitalWrite(yelPin1, LOW);
  digitalWrite(grnPin1, LOW);
  
  digitalWrite(redPin2, HIGH);
  digitalWrite(yelPin2, LOW);
  digitalWrite(grnPin2, LOW);
}