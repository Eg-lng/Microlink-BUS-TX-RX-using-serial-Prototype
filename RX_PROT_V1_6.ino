// Project : Microlink BUS
// Microlink BUS Reciever Prototype using serial
// Made by eg.lng / Follow me on Instagram @eg.lng , all right reserved, project KATZ systemes 
// PINOUT for arduino nano
// V1.6 / Last modification : 12/11/2025


#include <Arduino.h>

const int DATAOUT = 5; // PIN for the DATA
const int CLKOUT = 6; // PIN for the CLOCK

short int P = 0; // Parity Bit !! not used on this proto

unsigned long t1, t2; // Time for the sync 

int TMR[32]; // Lenght of the Data (33-1) = 32 Bits

void setup(){
Serial.begin(9600); // Serial
pinMode(DATAOUT,INPUT); // pin data 
pinMode(CLKOUT,INPUT); // pin clock 
Serial.println(" RX ready "); // Serial ready
t1 = millis(); // t1 initialisation
}

void loop(){

for (int i=1 ; i <= 32 ;i++ ) { // recieve loop

t2 = millis(); // t2 initialisation

if ((digitalRead(CLKOUT) == HIGH) && ((digitalRead(DATAOUT)) == HIGH)) { // Bit 1
  TMR[i] = 1 ;
            P++;
delayMicroseconds(45);
}

else if ((digitalRead(CLKOUT) == HIGH) && (digitalRead(DATAOUT) == LOW)){   // Bit 0
   TMR[i] = 0; 
delayMicroseconds(45);
}

else if (( t2 - t1 >= 200) && (digitalRead(CLKOUT) == LOW) && ((digitalRead(DATAOUT)) == LOW)){ // if nothing or no syncronized reset the loop
t1 = t2;
TMR[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32] = 0;
P = 0;
i=0;


}
else {            // if nothing dont count the loop
        i--;  
}
}

  Serial.print("| ");
  Serial.print(P);      // Parity Bit print
  Serial.print(":  ");

  for (int j=1 ; j <= 32 ;j++ ){   // Data Print
      Serial.print(TMR[j]);

  }  
  P = 0;

}
