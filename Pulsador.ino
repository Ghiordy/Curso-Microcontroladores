int led=8;
int button=14;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(button,INPUT);
  digitalWrite(led,LOW);}
void loop() {
  if(digitalRead(button)==1){
    delay(250);
    if(digitalRead(led)==0){
      digitalWrite(led,HIGH);}
      else{
        digitalWrite(led,LOW);}
        }
        }
