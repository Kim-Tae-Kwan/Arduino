#define sensor A0
#define VCC A2
#define GND A1

#define R 10
#define LGND 8

int val;

void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(VCC, OUTPUT);
  pinMode(GND, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(LGND, OUTPUT);

  digitalWrite(LGND, LOW);
  digitalWrite(VCC, HIGH);
  digitalWrite(GND, LOW);

}
boolean sw = false;
void loop() {
  val = analogRead(sensor);
  int light = map(val, 0, 1023, 0, 255);

  while (light > 20) {
    if (sw) {
      digitalWrite(R, HIGH);
      Serial.println("켜짐");
    }
    else {
      digitalWrite(R, LOW);
      Serial.println("꺼짐");
    }
    sw = !sw;
    light=0;
  }


  Serial.println(light);
  delay(300);

}
