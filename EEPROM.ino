

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
int dire=0;
int clave = 100;
//byte v1,v2;
char key;
String proba="";
int i = 0;
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

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
  EEPROM.write(dire,clave);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
}
  
void loop(){
  lcd.setCursor(0,0);
  lcd.blink();
  proba="";
  while(i<3){
  key = customKeypad.getKey();
  if(key=='*' && i==0){
    restablecer();
    proba="";
    i=0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.blink();
    key=NO_KEY;}
    
  if(key){
    lcd.print(String(key));
    proba+=String(key);
    i+=1;    }
    }

  lcd.setCursor(0,1);
  if (proba.toInt() == EEPROM.read(dire)){
    lcd.print("Correcta");
    digitalWrite(13,HIGH);}
  else{
      
    }
 
 i=0;
 lcd.noBlink();
 delay(2000);
 digitalWrite(13,LOW);
 lcd.clear();
} 

void restablecer(){
  lcd.clear();
  String nova= "";
  lcd.setCursor(0,1);
  lcd.print("Nueva clave");
  lcd.setCursor(0,0);
  lcd.blink();
  while(i<3){
    key = customKeypad.getKey();
    if(key){
      lcd.print(String(key));
      nova+=String(key);
      i+=1;}
    }
   clave=nova.toInt();
   EEPROM.update(dire,clave);
  }
  
