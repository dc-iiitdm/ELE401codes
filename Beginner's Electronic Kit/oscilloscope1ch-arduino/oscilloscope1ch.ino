/*BEGINNER'S ELECTRONIC KIT, BY  AAQUILA(EDM12B001)
 *                               ASHA(EDM12B003)
 *                               PRAVALLIKA(EDM12B004)
 * CODE FOR OSCILLOSCOPE                              
*/


/* CommaDelimitedOutput sketch */
#define ANALOG_IN_Ch1 0
#define ANALOG_IN_Ch2 5


void setup()
{
  Serial.begin(250000);
}
void loop()
{// Declaration
//int* val1 = 0;
//int myarraySize = 5;

// Allocation (let's suppose size contains some value discovered at runtime,
// e.g. obtained from some external source)
//if (val1 != 0) {
 //   val1 = (int*) realloc(val1, myarraySize * sizeof(int));
//} 
//else {
 //   val1 = (int*) malloc(size * sizeof(int));
//}

  
  //int i=0; 
  int val1 = analogRead(ANALOG_IN_Ch1); /* Reads values from analog Pin0 = Channel1 */
  int val2 = analogRead (ANALOG_IN_Ch2); /* Reads values from analog Pin1 = Channel2 */
 int amp1=(.0048*val1)+ .0984;
 int amp2=(.0048*val2)+ .0984;
 //int amp1=(.0008*val1)+ .0056;
 //int amp2=(.0008*val2)+ .0056;
 
 
  Serial.print('H'); /* Unique header to identify start of message */
  Serial.print(",");
  Serial.print((amp1), DEC);
  Serial.print(",");
  Serial.print((amp2), DEC);
  Serial.print(",");  /* Note that a comma is sent after the last field */
  //Serial.println(amp,DEC);
  // Serial.print(",");
  Serial.println();  /* send a cr/lf */
  delay(100); //This may be able to be faster than 50ms
 //i++;
}
