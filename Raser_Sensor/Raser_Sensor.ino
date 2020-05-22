int Raser = 13;
int vccPin = 12;
int GND = 11;
int Signal = 4;
int Svcc = 3;
int SGND = 2;


void setup() {
  //Raser 초기화
  pinMode(Raser, OUTPUT);
  pinMode(vccPin, OUTPUT);
  pinMode(GND, OUTPUT);
  digitalWrite(GND, LOW);
  digitalWrite(vccPin, HIGH);
  //버튼 초기화
  pinMode(Signal, INPUT_PULLUP);
  pinMode(Svcc, OUTPUT);
  pinMode(SGND, OUTPUT);
  digitalWrite(Svcc, HIGH);
  digitalWrite(SGND, LOW);

}
boolean sw = false;
void loop() {
  while (!chtsw(Signal)) {
    if (sw) {
      digitalWrite(Raser, LOW);
    }


    else digitalWrite(Raser, HIGH);
    sw=!sw;
  }

}

boolean chtsw(byte dx){
  boolean tsw=digitalRead(dx);
  while(tsw==digitalRead(dx)){}
  delay(30);
  return !tsw;
}




  
