int latchPin = 8;
int clockPin = 12;
int dataPinRed = 2;
int dataPinBlue = 3;
int dataPinGreen = 4;

void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPinRed, OUTPUT);
  pinMode(dataPinGreen, OUTPUT);
  pinMode(dataPinBlue, OUTPUT);
}

void loop() {
  displayHealth(1);
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