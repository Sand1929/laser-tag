/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 11;

int health = 8;
int latchPin = 8;
int clockPin = 9;
int dataPinRed = 0;
int dataPinBlue = 1;
int dataPinGreen = 2;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPinRed, OUTPUT);
  pinMode(dataPinGreen, OUTPUT);
  pinMode(dataPinBlue, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    if (health > 0) {
      --health;
    }
    Serial.println(health);
    displayHealth(health);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}

void displayHealth(int hp) {
    int numberToDisplay = 0.5 + pow(2,8-hp)-1;
  //for (int numberToDisplay = 0; numberToDisplay < pow(2,8); numberToDisplay++) {
  
    // take the latchPin low so 
    // the LEDs don't change while you're sending in bits:
    digitalWrite(latchPin, LOW);


    // shift out the high byte first:
    //shiftOut(dataPin, clockPin, MSBFIRST, (numberToDisplay>>8));  // most significant bit (MSB) goes out first;

   // shift out the low byte next:
    shiftOut(dataPinRed, clockPin, MSBFIRST, numberToDisplay);  // most significant bit (MSB) goes out first;
    shiftOut(dataPinGreen, clockPin, MSBFIRST, numberToDisplay);  // most significant bit (MSB) goes out first;

    digitalWrite(latchPin, HIGH);
 
    // pause before next value:
    delay(500);
}
