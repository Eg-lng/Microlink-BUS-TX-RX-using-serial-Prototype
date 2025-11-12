// Project : Microlink BUS
// Microlink BUS Transmitter Prototype using serial
// Made by eg.lng / Follow me on Instagram @eg.lng , all right reserved, project KATZ systemes 
// PINOUT for arduino nano
// V1.4 / Last modification : 12/11/2025


#include <Arduino.h>

const int DATAOUT = 5; // PIN for the DATA
const int CLKOUT = 6;  // PIN for the CLK

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
  Serial.begin(9600);        // Serial
    pinMode(DATAOUT,OUTPUT); // pin data 
    pinMode(CLKOUT,OUTPUT); // pin clock 
    Serial.println(" TX ready "); // Serial ready
}

void loop(){

   if (Serial.available() > 0) {
    commande = Serial.readStringUntil('\n');
    commande.trim(); 

    if (commande.equalsIgnoreCase("A")) { // random test you need to recieve (101 ... 10)
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
    else if (commande.equalsIgnoreCase("Z")) { // random test you need to recieve (000 ... 000)
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
  else if (commande.equalsIgnoreCase("E")) { // random test you need to recieve nothing
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
   else if (commande.equalsIgnoreCase("R")) { //  Still in devloppement !!random test you need to recieve (000 ... 01 )
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
    else if (commande.equalsIgnoreCase("T")) { // random test you need to recieve (111 ... 111)
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
