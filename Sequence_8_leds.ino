int p=31;
void setup() {
  for (int i=31; i<46; i=i+2){
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);}
  pinMode(21,INPUT);
  attachInterrupt(2,quieto,HIGH);
  Serial.begin(9600);
}

void loop() {
  for(int i=31;i<46;i=i+2){
    Serial.println(digitalRead(21));
    p=i;
    digitalWrite(i,HIGH);
    delay(250);
    digitalWrite(i,LOW);}
}

void quieto(){
  while(digitalRead(21)==1){
    delay(250);
    digitalWrite(p,HIGH);}
  digitalWrite(p,LOW);
  }

void quieto2(){
  digitalWrite(p,HIGH);}
