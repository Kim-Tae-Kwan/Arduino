#define VCC A2
#define GND A1
#define S A0

#define LGND 8
#define R 10
#define G 9
#define B 11

boolean sw = true;


void setup() {
  Serial.begin(9600);
  pinMode(VCC, OUTPUT);
  pinMode(GND, OUTPUT);
  pinMode(S, INPUT);
  digitalWrite(VCC, HIGH);
  digitalWrite(GND, LOW);

  pinMode(LGND, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  digitalWrite(LGND, LOW);
}

void loop() {
  int val = analogRead(S);

  if (val < 500) {

    switch (sw) {
      case true:
        digitalWrite(R, HIGH);
        delay(300);
        break;
      case false:
        digitalWrite(R, LOW);
        delay(300);
        break;
    }
    sw=!sw;

  }

  Serial.println(val);
  //delay(300);

}
