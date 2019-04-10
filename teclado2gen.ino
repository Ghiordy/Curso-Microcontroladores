#include <Keypad.h>
//#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal.h>
#include <Wire.h>

//LiquidCrystal_I2C lcd(0x27,16,2);
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 
const byte rowsCount = 4;
const byte columsCount = 4;

char c1,c2,c3,aux,anterior,seleccionado;

int pulsos = 0;
int x = -1;
int y = 0;

boolean cambio = false;
boolean tiempoSuperado = true;

long tiempoAnterior = 0;


char t0[] = {'0',' '};
char t1[] = {'1'};
char t2[] = {'A','B','C','a','b','c','2'};
char t3[] = {'D','E','F','d','e','f','3'};
char t4[] = {'G','H','I','g','h','i','4'};
char t5[] = {'J','K','L','j','k','l','5'};
char t6[] = {'M','N','O','m','n','o','6'};
char t7[] = {'P','Q','R','S','p','q','r','s','7'};
char t8[] = {'T','U','V','t','u','v','8'};
char t9[] = {'W','X','Y','Z','w','x','y','z','9'};

char keys[rowsCount][columsCount] = {
  {'D','#','0','*'},
  {'C','9','8','7'},
  {'B','6','5','4'},
  {'A','3','2','1'}
};
 
const byte rowPins[rowsCount] = {36, 34, 32, 30};
const byte columnPins[columsCount] = {44, 42, 40, 38};
 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rowsCount, columsCount);
 
void setup() {
   Serial.begin(9600);
   //lcd.init();
   //lcd.backlight();
   //lcd.display();
   lcd.begin(16,2);
   lcd.clear();
}
 
void loop() {
  char key = keypad.getKey();
  
  tiempoSuperado = millis() > tiempoAnterior + 1000;

   if(c1=='C' and c2=='L' and c3=='C' and (tiempoSuperado)){
      lcd.clear();
      x=-1;
      y=0;
      pulsos=0;
    }
    
  if(key){
    boolean cambio = key==anterior && !tiempoSuperado;
  
    if(tiempoSuperado){
      if(key==anterior) x++;
      pulsos=0;
    }
    
    if(key!=anterior){
      tiempoSuperado =true;
      pulsos = 0;
      x++;
    }

    tiempoAnterior = millis();

    switch (key) {
      case '0':
        pulsos = cambio ? (++pulsos%sizeof(t0)) : 0;
        seleccionado = t0[pulsos];
        break;
      case '1':
        pulsos = cambio? (++pulsos%sizeof(t1)) : 0;
        seleccionado = t1[pulsos];
        break;
      case '2':
        pulsos = cambio ? (++pulsos%sizeof(t2)) : 0;
        seleccionado = t2[pulsos];
        break;
      case '3':
        pulsos = cambio ? (++pulsos%sizeof(t3)) : 0;
        seleccionado = t3[pulsos];
        break;
      case '4':
        pulsos = cambio ? (++pulsos%sizeof(t4)) : 0;
        seleccionado = t4[pulsos];
        break;
      case '5':
        pulsos = cambio ? (++pulsos%sizeof(t5)) : 0;
        seleccionado = t5[pulsos];
        break;
      case '6':
        pulsos = cambio ? (++pulsos%sizeof(t6)) : 0;
        seleccionado = t6[pulsos];
        break;
      case '7':
        pulsos = cambio ? (++pulsos%sizeof(t7)) : 0;
        seleccionado = t7[pulsos];
        break;
      case '8':
        pulsos = cambio ? (++pulsos%sizeof(t8)) : 0;
        seleccionado = t8[pulsos];
        break;
      case '9':
        pulsos = cambio ? (++pulsos%sizeof(t9)) : 0;
        seleccionado = t9[pulsos];
        break;
      default:
        seleccionado = key;
    }
    
    c3 = cambio ? c3 : c2;
    c2 = cambio ? c2 : c1;
    c1 = cambio ? seleccionado : c1;
    
    anterior = key;
    y = x == 16 ? ++y%2 : y ;
    x=x%16;
    lcd.setCursor(x,y);
    lcd.print(seleccionado);
  }
}
