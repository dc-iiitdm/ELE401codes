const int pinA = 4;
const int pinB = 5;
const int pinC = 6;
const int pinD = 7;
byte command = 0;
const int rHigh = 555;
const int rLow = 100;
int randomPin;
void pinDo(int pin);
void allOn();
void allOff();
void randomStart();
void flashThrough();

void setup()
  {               
  pinMode (pinA, OUTPUT); // set the relays pin as an output
  pinMode (pinB, OUTPUT); //
  pinMode (pinC, OUTPUT); //
  pinMode (pinD, OUTPUT); //
 
  allOff(); // make sure all pins are off to start
 
  Serial.begin(9600);
 
  if (Serial.available() > 0) // Start serial transfer
    {
    command = Serial.read(); // Set command to equal the serial data
    }
  }

void loop()
  {
   if (Serial.available() > 0)
     {
    command = Serial.read();
    switch (command)
      {
     case 1: // Relay 1
       pinDo (pinA);
       break;
     case 2: // Relay 2
       pinDo (pinB);
       break;
     case 3: // Relay 3
       pinDo (pinC);
       break;
     case 4: // Relay 4
       pinDo (pinD);
       break;
     case 5: // The random function
       randomStart();
       break;
     case 6: // Turn all pins on
       allOn();
       break;
     case 7: // Turn all pins off
       allOff();
       break;
     case 8: // Start flashing pattern
       while (command != 6 && command != 7)
         {
           flashOn();
           command = Serial.read(); // Check for new serial data
        }
      }
    }
  }

void pinDo(int pin)
  {
    if (digitalRead(pin) == LOW)
      {
      digitalWrite(pin, HIGH);
      }
      else
      {
      digitalWrite(pin, LOW);
      }
  }

void randomStart ()
  {
    while (command != 6 && command != 7)
      {
      randomPin = random(pinA, pinD + 1);
      if (digitalRead(randomPin) == LOW)
        {
      digitalWrite (randomPin, HIGH);
      delay (random(rLow, rHigh));
        }
      else
        {
      digitalWrite (randomPin, LOW);
      delay (random(rLow, rHigh));
      command = Serial.read(); // Check for new serial data, if so, exit the random flashing
      /* These 2 if statements are present in the 5th case because I wanted the pins to immediately
      turn on or off depending on the command it receives while in the random portion of code.*/
      if (command == 6)
        {
          allOn();
        }
      if (command == 7)
        {
         allOff();
        }
        }
      }
  }
void flashOn ()
  {
    digitalWrite(pinA, HIGH); // all on
    delay(150);
    digitalWrite(pinB, HIGH);
    delay(150);
    digitalWrite(pinC, HIGH);
    delay(150);
    digitalWrite(pinD, HIGH);
    delay(400);
    allOff();
    allOn();
    allOff();
    allOn();
    allOff();
    flashThrough();
    flashThrough();
    flashBack();
    flashBack();
  }

void allOn ()
  {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    delay(300);
  }

void allOff ()
  {
    digitalWrite(pinA, LOW); // next phase
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    delay(350);
  }

void flashThrough ()
  {
    digitalWrite(pinA, HIGH); // next phase
    delay(200);
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    delay(200);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    delay(200);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    delay(200);
    digitalWrite(pinD, LOW);
  }

void flashBack ()
  {
    digitalWrite(pinD, HIGH); // next phase
    delay(200);
    digitalWrite(pinD, LOW);
    digitalWrite(pinC, HIGH);
    delay(200);
    digitalWrite(pinC, LOW);
    digitalWrite(pinB, HIGH);
    delay(200);
    digitalWrite(pinB, LOW);
    digitalWrite(pinA, HIGH);
    delay(200);
    digitalWrite(pinA, LOW);
  }