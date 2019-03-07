#include <LiquidCrystal.h>
#include <TimerOne.h>
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int count_1=0;
int ena=2;
void setup() {
  lcd.begin(16,2);
  lcd.clear();
  Serial.begin(9600);
  pinMode(22,INPUT);
  Timer1.initialize(1000);
  Timer1.start();
  Timer1.attachInterrupt(conteo_int);
  //attachInterrupt(2,inicio,RISING);
  //attachInterrupt(2,fin,FALLING);
  //pinMode(22,INPUT);
}
void loop(){
  //if(ena==1){muestra();}
  }
void muestra() {
  lcd.setCursor(0,0);
  lcd.print(String(count_1));
  int f= (1/(count_1))*10^3;
  lcd.print("   F="+String(f));
  }
void conteo_int(){
  if(digitalRead(22)==1 & ena==2){
    count_1++;
    //lcd.setCursor(0,0);
    //lcd.print(String(count_1));
    //Serial.print(count_1);
    //int f = (1/(count_1))*10^3;}
    //Serial.println("f = "+((1/(count_1))*10^3));
  }
  if(digitalRead(22)==0 & ena==2 & count_1>2){ena=1;muestra();}
  }
//void inicio(){}
//void fin(){}
