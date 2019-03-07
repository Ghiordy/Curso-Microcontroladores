#include <LiquidCrystal.h>
#include <TimerOne.h>
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
boolean ena=false;
int count=1;
void setup() {
  Timer1.initialize(1000000);
  Timer1.start();
  //Timer1.attachInterrupt(cambio);
  Timer1.attachInterrupt(conteo_int);
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
  lcd.begin(16,2);
  lcd.clear();
}

void loop() {
  //lcd.clear();
  lcd.setCursor(0,0);
  //if(ena==true){digitalWrite(LED_BUILTIN,HIGH),lcd.print("True ");}
  //else{digitalWrite(LED_BUILTIN,LOW),lcd.print("False");}
  lcd.print("  "+String(count));
  if(count%2==0){digitalWrite(LED_BUILTIN,HIGH);}
  else{digitalWrite(LED_BUILTIN,LOW);}
  
}

void cambio(){
  if(ena==true){ena==false;}
  else{ena==true;}
  }

void conteo_int(){
  count++;
  }
