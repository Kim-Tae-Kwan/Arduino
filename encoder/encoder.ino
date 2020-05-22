#define GND 2
#define VCC 3
#define SW  4
#define DT  5
#define CLK 6

int oldA = LOW;
int oldB = LOW;
int cnt = 0;

void Encoder(int newA, int newB)
{
  if (newA != oldA || newB != oldB) // 펄수 발생
  {
    if (oldA == LOW && newA == HIGH) // 상승에지
    {
      if (oldB == LOW) cnt++;
      else cnt--;


    }

    Serial.println(cnt);

  }
  oldA = newA;
  oldB = newB;
}


void setup() {
  Serial.begin(9600);

  pinMode(GND, OUTPUT);
  pinMode(VCC, OUTPUT);
  pinMode(SW, INPUT_PULLUP);
  pinMode(DT, INPUT_PULLUP);
  pinMode(CLK, INPUT_PULLUP);
  digitalWrite(GND, LOW);
  digitalWrite(VCC, HIGH);

}

void loop() {
  int newA = digitalRead(DT);
  int newB = digitalRead(CLK);

  if (digitalRead(SW) == 0) {
    cnt = 0;
    Serial.println(cnt);
    delay(300);
  }
  Encoder(newA, newB);



}
