/*******************************************
 * Differential Amplifier and 
 * internal reference test for LGT8F328P
 * Using new differential_amplifier library.
 * by LaZsolt
 *******************************************/
 
#include "differential_amplifier.h"

void setup() {
  analogReadResolution(12);
  Serial.begin(38400);
  Serial.println("start");
  Serial.println();
} // end setup()

uint32_t v;

void loop() {
  analogReference(INTERNAL1V024);
  Sprintline( "Power Supply: " , ( analogRead(VCCM) * 5 ) / 4 , " mV" );

  analogReference(INTERNAL1V024);
  Serial.println("Ref: 1.024V");
  Sprintline( "A7: " , analogRead(A7) / 4 , " mV" );
  Sprintline( "A3: " , analogRead(A3) / 4 , " mV" );
  Serial.println();
  analogReference(INTERNAL2V048);
  Serial.println("Ref: 2.048V");
  Sprintline( "A7: " , analogRead(A7) / 2 , " mV" );
  Sprintline( "A3: " , analogRead(A3) / 2 , " mV" );
  Serial.println();
  analogReference(INTERNAL4V096);
  Serial.println("Ref: 4.096V");
  Sprintline( "A7: " , analogRead(A7) , " mV" );
  Sprintline( "A3: " , analogRead(A3) , " mV \n-----------" );

  if ( analogRead(A3) > analogRead(A7) ) {
    Serial.println("*********************************************************************");
    Serial.println("The negative input voltage (A3) greater than the positive input (A7).");
    Serial.println("The differential amplifier output will be zero. Plus offset. ");
    Serial.println("*********************************************************************");
  }
  delay(100);

  analogReference(INTERNAL1V024);
  Sprintline( "Ref: 1,024V \n A7-A3 = " , analogDiffRead(A3, A7, GAIN_1) / 4 , " mV \n-----------" );
  delay(100);

  analogReference(INTERNAL2V048);
  Sprintline( "Ref: 2,048V \n A7-A3 = " , analogDiffRead(A3, A7, GAIN_1) / 2 , " mV \n-----------" );
  delay(100);
  
  analogReference(INTERNAL4V096);
  Sprintline( "Ref: 4,096V \n A7-A3 = " , analogDiffRead(A3, A7, GAIN_1) , " mV \n-----------" );
  delay(100);

  analogReference(DEFAULT);
  Sprintline( "Ref: VCC \n A7-A3 = " , analogDiffRead(A3, A7, GAIN_1) , "\n-----------" );
  delay(100);

  analogReference(INTERNAL2V048);
  Sprintline( "Ref: 2,048V \n (A7-A3) * 1 = " , analogDiffRead(A3, A7, GAIN_1) , "\n-----------" );
  delay(100);

  analogReference(INTERNAL2V048);
  Sprintline( "Ref: 2,048V \n (A7-A3) * 8 = " , analogDiffRead(A3, A7, GAIN_8) , "\n-----------" );
  delay(100);
  
  Sprintline( "Ref: 2,048V \n (A7-A3) *16 = " , analogDiffRead(A3, A7, GAIN_16) , "\n-----------" );
  delay(100);

  Sprintline( "Ref: 2,048V \n (A7-A3) *32 = " , analogDiffRead(A3, A7, GAIN_32) , "\n-----------" );
  delay(10000);
  
  Serial.println("\n\n\n");
} // end loop()

void Sprintline(const char* t1, uint32_t val, const char* t2) {
  Serial.print(t1);
  Serial.print(val,DEC);
  Serial.println(t2);
} // end Sprintline()
