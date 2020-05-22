#define VCC 9
#define GND 8
#define S 10

void setup() {
  pinMode(VCC,OUTPUT);
  pinMode(GND,OUTPUT);
  pinMode(S,OUTPUT);
  digitalWrite(VCC,HIGH);
  digitalWrite(GND,LOW);
  
}

void loop() {
   digitalWrite(S,HIGH);
   delay(1000);
   digitalWrite(S,LOW);
   delay(1000);
}
