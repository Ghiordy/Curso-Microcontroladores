

/* @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| #
*/
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
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
char texto[3] = {' ',' ',' '};
char texto2[3] = {' ',' ',' '};
boolean retorno = false;
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//char texto[3] = {' ',' ',' '};
//char texto2[3] = {' ',' ',' '};
//boolean retorno = false;

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

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  lcd.begin(16,2);
  lcd.clear();
  Serial.begin(9600);
}
  
void loop(){
  retorno = false;
  int i =1;
  lcd.setCursor(0,0);
  lcd.blink();
  do{
  char customKey = customKeypad.getKey();
  if (customKey){
    lcd.print(customKey);
    texto[i]+=String(customKey);
    Serial.print(i);
    i++;
    }
  }while(i<=3);
  i=1;
  lcd.setCursor(0,1);
  do{
  char customKey = customKeypad.getKey();
  if (customKey){
    lcd.print(customKey);
    texto2[i]+=String(customKey);
    i++;
    Serial.print(i);}
  }while(i<=3);
  lcd.setCursor(5,1);
  retorno = true;
  for(int j=0;j<=3;j++){
    Serial.print("t"+String(texto[j]));
    Serial.println("t2"+String(texto2[j]));
    if (not(texto[j]==texto2[j])){
      retorno=false;
      break;
    }
    
    }
  if(retorno){
    lcd.print("Correcta");}
  else{lcd.print("Incorrecta");}
  delay(5000);
  }
  
  
