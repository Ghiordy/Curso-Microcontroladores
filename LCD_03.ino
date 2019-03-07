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

// include the library code:
#include <LiquidCrystal.h>
int button = A0;
int select = A1;
int pos = 1;
int attem = 3;
int number = 0;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(button,INPUT);
  pinMode(select,INPUT);
  lcd.begin(16, 2);
  lcd.display();
  AsigNumber();
}

int AsigNumber(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Guess! ");
  attem = 3;
  lcd.setCursor(0,1);
  lcd.print(String(attem)+" attempts left.");
  number = random(1,10);
  return number;}

void loop() {
  lcd.setCursor(15,0);
  lcd.print(String(number));
  delay(10);
  if(digitalRead(button)==1){
    delay(250);
    if(pos==10){pos=0;}
    else{pos++;}}
    lcd.setCursor(10,0);
    lcd.print(" ");
    lcd.setCursor(10,0);
    lcd.print(String(pos));
  if(digitalRead(select)==1){
    attem = attem-1;
    delay(250);
    check(number, pos);}
}

void check(int number, int pos){
  lcd.setCursor(0,1);
  if(pos==number){
    lcd.print("You've winned.  ");
    delay(5000);
    AsigNumber();}
  else{if(attem==0){
    lcd.print("You've losed.   ");
    delay(3000);
    AsigNumber();}
    else{lcd.print(String(attem)+" attempts left.");}}}
