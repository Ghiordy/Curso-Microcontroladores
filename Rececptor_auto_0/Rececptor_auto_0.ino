#include <VirtualWire.h>
#include <NewPing.h>
#include <TimerOne.h>

// Proximidad delantera
const int UltrasonicPin = 5;
const int MaxDistance = 200;
NewPing sonar(UltrasonicPin, UltrasonicPin, MaxDistance);

// Puente H
int ena = 8;
int in1 = 24;
int in2 = 25;

// Receptor RF
const int dataPin = 9;
const int ledPin = 13;

// Luces
int LDR = A3;
int STOP = 30;
int FRONT = 32;
int BACK = 34;
int LEVEL;

// Direccionales
//int RIGHT_i = 2;
//int LEFT_i = 3;
int RIGHT_o = 31;
int LEFT_o = 33;
int countR = 1;
int countL = 1;
int enaR = 0;
int enaL = 0;

//Mando
int right = A0;
int left = A1;

// Variables 
int power = 0;
 
void setup()
{
    Serial.begin(9600);
    vw_setup(2000);
    vw_set_rx_pin(dataPin);
    vw_rx_start();

  //pinMode(x,INPUT);
  //pinMode(y,INPUT);
  pinMode(right,OUTPUT);
  pinMode(left,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(ena,OUTPUT);
  //pinMode(RIGHT_i,INPUT);
  //pinMode(LEFT_i,INPUT);
  pinMode(RIGHT_o,OUTPUT);
  pinMode(LEFT_o,OUTPUT);
  attachInterrupt(0,flasherR,HIGH);
  attachInterrupt(1,flasherL,HIGH);
  analogWrite(ena,0);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(right,LOW);
  digitalWrite(left,LOW);
  Serial.begin(9600);
}
 
void loop()
{
    // Regulación Luces dependiendo del ambiente
    LEVEL = map(analogRead(LDR),0,1023,0,255);
    analogWrite(FRONT,LEVEL);
    analogWrite(STOP,LEVEL);

  
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    
    if (vw_get_message(buf, &buflen)) 
    {
      /*digitalWrite(ledPin, true);
      Serial.print("Mensaje: ");
      for (int i = 0; i < buflen; i++)
      {
         Serial.print((char)buf[i]);
      }
      Serial.println("");*/
      if((char)buf[1] == 'l'){// Izquierda
    digitalWrite(left,HIGH);}
    else{if((char)buf[1] == 'r'){// Derecha
      digitalWrite(right,HIGH);}
      else{
        digitalWrite(left,LOW);
        digitalWrite(right,LOW);}}
   if((char)buf[0] == 'f'){ //Adelante
    if(sonar.ping_cm()>5){
      if(power<0){power = 0;}
      digitalWrite(BACK,HIGH);
      if(power < 200){power = power + 25;}
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      analogWrite(ena,power);
      }
   }
    else{
      if((char)buf[0] == 'b'){// Atrás
        if(power>0){power = 0;}
        if(power > -200){power = power - 25;}
        digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
        analogWrite(ena,-power);// power requiere arranque suave
      }
      else{
        digitalWrite(in1,LOW);
        digitalWrite(in2,LOW);
        power=0;
        analogWrite(ena,0);
      }
    }
   }
   }

   
void flasherR(){
  delay(150);
  //digitalWrite(31,HIGH);
  //Timer1.stop();
  if(enaR==0){
    Timer1.initialize(350000);
    Timer1.start();
    Timer1.attachInterrupt(conteo_R);
    enaR=1;
    }
  else{
    Timer1.stop();
    enaR=0;
    digitalWrite(RIGHT_o,LOW);
    countR=1;
    }
}

void conteo_R(){
  countR++;
  }

void flasherL(){
  delay(150);
  //digitalWrite(31,HIGH);
  //Timer1.stop();
  if(enaL==0){
    Timer1.initialize(350000);
    Timer1.start();
    Timer1.attachInterrupt(conteo_L);
    enaL=1;
    }
  else{
    Timer1.stop();
    enaL=0;
    
    digitalWrite(LEFT_o,LOW);
    countL=1;
    }
}

void conteo_L(){
  countL++;
  }
