#define VCC 9
#define GND 8
#define DATA 10

int value=0;

void setup() {
  Serial.begin(9600);
  pinMode(VCC,OUTPUT);
  pinMode(GND,OUTPUT);
  pinMode(DATA,INPUT);

  digitalWrite(VCC,HIGH);
  digitalWrite(GND,LOW);

}

void loop() {
  value=digitalRead(DATA);
  Serial.println(value);
  

}
