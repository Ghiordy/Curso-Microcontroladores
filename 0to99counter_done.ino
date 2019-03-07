int value = 0;
const int nbrDigits= 2;
const int segmentPins[] = {
  9,8,7,6,5,4,3,2};
const int digitPins[nbrDigits] = {
  10, 11};
const int numeral[10] = {
  B11111100, // 0
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B10111110, // 6
  B11100000, // 7
  B11111110, // 8
  B11110110, // 9};
};
void setup() {
  for(int i=0; i < 8; i++)
    pinMode(segmentPins[i], OUTPUT);
  for(int i=0; i < nbrDigits; i++)
    pinMode(digitPins[i], OUTPUT);
  digitalWrite(digitPins[0],LOW);
  digitalWrite(digitPins[1],LOW);}

void loop() {
  if (value==99){value=0;}
  else{
    value+=1;}
for(int i=0; i<10; i++){
  if(value<10){showS0(value%10);}
  else{
  showS0(value%10);
  showS1(value/10);}}}

void showS0(int value0){
  digitalWrite(digitPins[0],LOW);
  digitalWrite(digitPins[1],HIGH);
  for(int segment=1; segment<8;segment++){
    boolean isBitSet = bitRead(numeral[value0], segment);
    digitalWrite(segmentPins[segment],isBitSet);}
    delay(100);
}
void showS1(int value1){
  digitalWrite(digitPins[0],HIGH);
  digitalWrite(digitPins[1],LOW);
  for(int segment=1; segment<8;segment++){
    boolean isBitSet = bitRead(numeral[value1], segment);
    digitalWrite(segmentPins[segment],isBitSet);}
    delay(100);
}
