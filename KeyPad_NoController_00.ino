
/*
Keypad Interfacing with Arduino Without Keypad Library
 Author : Kunchala Anil
 It is implemented using a method called Column Searching
 */

#include <LiquidCrystal.h>
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int p=0;

const int row_pin[] = {36, 34, 32, 30};
const int col_pin[] = {44, 42, 40, 38}; // defining row and column pins as integer arrays

const int rows = 4, cols = 4; //defining the multi dimensional array size constants 

const char key[rows][cols] = {               // defining characters //for keystrokes in Multidimensional Array
  {'D','#','0','*'},
  {'C','9','8','7'},
  {'B','6','5','4'},
  {'A','3','2','1'}
};

void setup(){

  Serial.begin(9600); //begin the serial communication

  for(int i = 0; i<4; i++)
  {
    pinMode(row_pin[i],OUTPUT); //Configuring row_pins as Output Pins
    digitalWrite(row_pin[i],HIGH);//write HIGH to all row pins

    pinMode(col_pin[i],INPUT_PULLUP);//configure column pin as Input and activate internal //Pullup resistor

  }//end of for loop
  
  lcd.begin(16,2);
  lcd.clear();
  
}//end of setup


void loop(){
  char key = read_key();
  if(key !='\n'){
    Serial.println(key);
    delay(100);
  }
  if(p==16){
    lcd.setCursor(0,1);}
  if(p==32){
    lcd.setCursor(0,0);
    p=0;}
  lcd.blink();
  if (key=='1' || key=='2' || key=='3' || key=='A' || key=='4' || key=='5' || key=='6' || key=='B' || key=='7' || key=='8' || key=='9' || key=='C' || key=='*' || key=='0' || key=='#' || key=='D'){
    if(
      key=='*'){lcd.clear();
      lcd.setCursor(0,0),p=0;}
    else{
      lcd.print(key); 
      p++;}
  }
}//end of loop

char read_key(){
  delay(250);
  for(int row = 0;row < 4;row++)
  {
    digitalWrite(row_pin[0],HIGH);
    digitalWrite(row_pin[1],HIGH);
    digitalWrite(row_pin[2],HIGH);
    digitalWrite(row_pin[3],HIGH);
    digitalWrite(row_pin[row],LOW);
    //Serial.println(row_pin[row]);

    for(int col = 0;col<4;col++)
    {
      int col_state = digitalRead(col_pin[col]);
      if(col_state == LOW)
      {
        return key[row][col];
      }//end of if 
    }//end of col for loop
  }//end of row for loop
  return '\n';
}//end of read_key
