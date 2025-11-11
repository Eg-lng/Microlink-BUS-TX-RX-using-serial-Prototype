#include <Arduino.h>

const int DATAOUT = 5; // PIN for the DATA
const int CLKOUT = 6; // PIN for the CLOCK

short int P = 0;

unsigned long t1, t2; // temps pour la comp

int TMR[32];

void setup(){
Serial.begin(9600);
pinMode(DATAOUT,INPUT); // pin data 
pinMode(CLKOUT,INPUT); // pin clock 
t1 = millis();
}

void loop(){

for (int i=0 ; i <= 31 ;i++ ) {

t2 = millis();

if ((digitalRead(CLKOUT) == HIGH) && ((digitalRead(DATAOUT)) == HIGH)) {
  TMR[i] = 1 ;
            P++;
delayMicroseconds(45);
}

else if ((digitalRead(CLKOUT) == HIGH) && (digitalRead(DATAOUT) == LOW)){
   TMR[i] = 0;
delayMicroseconds(45);
}

else if (( t2 - t1 >= 200) && (digitalRead(CLKOUT) == LOW) && ((digitalRead(DATAOUT)) == LOW)){
t1 = t2;
TMR[32] = 0;
P = 0;
i=0;


}
else {
        i--;
}
}

  Serial.print("| ");
  Serial.print(P);
  Serial.print(":  ");

  for (int j=0 ; j <= 31 ;j++ ){
      Serial.print(TMR[j]);

  }  
  P = 0;

}

