#include <LiquidCrystal.h>
#include <TimerOne.h>
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//boolean ena=false;
int count=1;
void setup() {
  Timer1.initialize(250*4);
  Timer1.start();
  //Timer1.attachInterrupt(cambio);
  Timer1.attachInterrupt(conteo_int);
  pinMode(22,OUTPUT);
  digitalWrite(22,LOW);
  //lcd.begin(16,2);
  //lcd.clear();
}

void loop() {
  //lcd.clear();
  //if(ena==true){digitalWrite(LED_BUILTIN,HIGH),lcd.print("True ");}
  //else{digitalWrite(LED_BUILTIN,LOW),lcd.print("False");}
}
void conteo_int(){
  if(count==2){
    count=1;}
  else{count++;}
  //lcd.setCursor(0,0);
  //lcd.print(String(count));
  //lcd.print("   ");
  if(count<2){digitalWrite(22,HIGH);}
  else{digitalWrite(22,LOW);}
  }
