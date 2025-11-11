#include <Arduino.h>

const int DATAOUT = 5; // PIN for the DATA
const int CLKOUT = 6;

String commande = "";

void bit1(); 
void bit0();


void bit1()
{
    digitalWrite(DATAOUT,1);
    digitalWrite(CLKOUT,1);
    delayMicroseconds(40); // 40 microsecondes
    digitalWrite(DATAOUT,0);
    digitalWrite(CLKOUT,0);
    delayMicroseconds(40); // 40 microsecondes
}

void bit0()
{
    digitalWrite(CLKOUT , 1);
    delayMicroseconds(40); // 40 microsecondes
    digitalWrite(CLKOUT ,0);
    delayMicroseconds(40); // 40 microsecondes
}
void setup(){
  Serial.begin(9600);
    pinMode(DATAOUT,OUTPUT); // pin data 
    pinMode(CLKOUT,OUTPUT); // pin clock 
    Serial.println("ready");
}

void loop(){

   if (Serial.available() > 0) {
    commande = Serial.readStringUntil('\n');
    commande.trim(); 

    if (commande.equalsIgnoreCase("A")) {
      bit1();
      bit0();
      bit1();
      bit0();
      bit1();
      bit0();
      bit1();
      bit0();
      bit1();
      bit0();
      bit1();
      bit0();
      bit1();
      bit0();
      bit1();
      bit0();
      bit1();
      bit0();
      bit1();
      bit0();
      bit1();
      bit0();
      bit1();
      bit0();
      bit1();
      bit0();
      bit1();
      bit0();
      bit1();
      bit0();
      bit1();
      bit0();
      Serial.println(" 1 ");
    } 
    else if (commande.equalsIgnoreCase("Z")) {
      bit0(); 
      bit0();
      bit0();
      bit0();
      bit0(); 
      bit0();
      bit0();
      bit0();
      bit0(); 
      bit0();
      bit0();
      bit0();
      bit0(); 
      bit0();
      bit0();
      bit0();
      bit0(); 
      bit0();
      bit0();
      bit0();
      bit0(); 
      bit0();
      bit0();
      bit0();
      bit0(); 
      bit0();
      bit0();
      bit0();
      bit0(); 
      bit0();
      bit0();
      bit0();
      Serial.println(" 0 ");
    } 
  else if (commande.equalsIgnoreCase("E")) {
      bit0(); 
      bit0();
      bit0();
      bit0();
      bit0(); 
      bit0();
      bit0();
      bit0();
      bit0(); 
      bit0();
      bit0();

      Serial.println(" ERROR ");
    } 
   else if (commande.equalsIgnoreCase("R")) {
      bit0(); 
      bit0();
      bit0();
      bit0();
      bit0(); 
      bit0();
      bit0();
      bit0();
      bit0(); 
      bit0();
      bit0();
      bit0();
      bit0(); 
      bit0();
      bit0();
      bit0();
      bit0(); 
      bit0();
      bit0();
      bit0();
      bit0(); 
      bit0();
      bit0();
      bit0();
      bit0(); 
      bit0();
      bit0();
      bit0();
      bit0(); 
      bit0();
      bit0();
      bit1();
      bit1();
      bit1();
      Serial.println(" OVERFLOW ");
    } 
    else if (commande.equalsIgnoreCase("T")) {
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      bit1();
      Serial.println(" ALL 1 ");
    } 
   }
}
