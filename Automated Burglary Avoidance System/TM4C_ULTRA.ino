#define trigPin 28 // Trigger Pin
#define echoPin 29 // Echo Pin
#define LEDPin 27 // Onboard LED

int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup() {
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);

digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);

//Calculate the distance (in cm) based on the speed of sound.
distance = duration/58.2;

if (distance >= 15 || distance <= minimumRange)
{
  /* Send a negative number to computer and Turn LED ON to indicate "out of range" */
Serial.println("OR");
digitalWrite(LEDPin, HIGH);
} 
else 
{
  /* Send the distance to the computer using Serial protocol, and turn LED OFF to indicate successful reading. */
  Serial.print(distance); 
Serial.println(" cm");
digitalWrite(LEDPin, LOW);
} //Delay 50ms before next reading. 
delay(50);
}
