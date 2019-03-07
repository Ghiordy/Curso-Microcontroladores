/* The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3) */
// #include <Keypad.h>
#include <LiquidCrystal.h>
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int i=0;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'D','#','0','*'},
  {'C','9','8','7'},
  {'B','6','5','4'},
  {'A','3','2','1'} 
};
byte rowPins[ROWS] = {36, 34, 32, 30}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {44, 42, 40, 38}; //connect to the column pinouts of the keypad

char keys[4][4] = {
  { '1','2','3', 'A' },
  { '4','5','6', 'B' },
  { '7','8','9', 'C' },
  { '#','0','*', 'D' }
  };

//initialize an instance of class NewKeypad
//Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
void setup(){
  for (int i=0; i<ROWS; i++){
    pinMode(rowPins[i],OUTPUT);}
  }
  for (int i=0; i<COLS; i++){
    pinMode(rowPins[i],INPUT_PULLUP);
  }
  lcd.begin(16,2);
  lcd.clear();
  }

void loop(){
  
  }
