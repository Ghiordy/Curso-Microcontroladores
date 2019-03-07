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
int led = 13;
int pos = 1;
boolean stat = false;
boolean exe = false;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(button,INPUT);
  pinMode(select,INPUT);
  pinMode(led,OUTPUT);
  lcd.begin(16, 2);
  lcd.print("1. Turn On LED. ");
  lcd.setCursor(0,0);
}

void loop() {
  if(pos==1 && digitalRead(button)==1){
    pos=2;
    lcd.print("2. Turn Off LED.");
    delay(250);}
  if(pos==2 && digitalRead(button)==1){
    pos=3;
    lcd.print("3. Blink LED.   ");
    delay(250);}
  if(pos==3 && digitalRead(button)==1){
    pos=1;
    lcd.print("1. Turn On LED. ");
    delay(250);}
    if(digitalRead(select)==1){
      switch(pos){
        case 1:
        encender();
        exe = false;
        delay(250);
        break;
        case 2:
        apagar();
        exe = false;
        delay(250);
        break;
        case 3:
        parpadear();
        exe = true;
        break;
        default:
        lcd.print("Error");
        }}
        else{if(exe==true){parpadear();}}
  lcd.setCursor(0,0);
  lcd.blink();
  lcd.display();
}

void encender(){
  digitalWrite(led,HIGH);
  boolean stat = true;}
void apagar(){
  digitalWrite(led,LOW);
  boolean stat = false;}
void parpadear(){
  if(stat==false){
    digitalWrite(led,HIGH);
    stat= true;
    delay(100);}
  if(stat=true){
    digitalWrite(led,LOW);
    stat=false;
    delay(100);}}
