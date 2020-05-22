int vccPin = 9;
int gndPin = 10;
int sigPin = 8;
int value = 0;
int a = 0;

#define R 4
#define G 3
#define B 5
#define GND 2

void LED() {
  a = random(3,6);

  switch (a) {
    case 3:
      digitalWrite(R, LOW);
      digitalWrite(G, HIGH);
      digitalWrite(B, LOW);
      Serial.println(a);
      Serial.println("G");
      
      break;
    case 4:
      digitalWrite(R, HIGH);
      digitalWrite(G, LOW);
      digitalWrite(B, LOW);
      Serial.println(a);
      Serial.println("R");
      
      break;
    case 5:
      digitalWrite(R, LOW);
      digitalWrite(G, LOW);
      digitalWrite(B, HIGH);
      Serial.println(a);
      Serial.println("B");
      
      break;
  }



}


void setup() {
  Serial.begin(9600);
  //기울기 센서 초기화
  pinMode(vccPin, OUTPUT);
  pinMode(gndPin, OUTPUT);
  pinMode(sigPin, INPUT_PULLUP);
  //LED 초기화
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(GND, OUTPUT);
  digitalWrite(GND, LOW);


}

void loop() {
  value = digitalRead(sigPin);

  if (value == 0) {
    LED();
    
  }
  else digitalWrite(a, LOW);

  //Serial.print("Sensor value: ");
  //Serial.println(a);
  delay(100);

}
