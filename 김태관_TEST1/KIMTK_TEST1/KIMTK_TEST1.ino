//LED 핀 번호
#define LGND 8
#define G    9
#define R    10
#define B    11

//엔코더 핀 번호
#define EGND A0
#define VCC  A1
#define SW   A2
#define DT   A3
#define CLK  A4

//엔코더 변수 선언
int oldA = LOW;
int oldB = LOW;
int cnt = 255;
int curcolor = R;

//밝기 조절
void brightness(int newA, int newB)
{
  if (newA != oldA || newB != oldB) // 펄수 발생
  {
    if (oldA == LOW && newA == HIGH) // 상승에지
    {
      if (oldB == LOW)
      {
        cnt += 50;
        if (cnt > 255) cnt = 255;
      }
      else
      {
        cnt -= 50;
        if (cnt < 0) cnt = 0;
      }
    }
  }
  oldA = newA;
  oldB = newB;
  analogWrite(curcolor, cnt);
}

//색 선택
void colorselect(int sw)
{
  if (sw == 0)
  {
    analogWrite(curcolor++, 0);
    if (curcolor > 11) curcolor = 9;
    analogWrite(curcolor, cnt);
    delay(300);
  }
}

void setup() {
  Serial.begin(9600); // 시리얼 통신 연결

  //LED 핀 모드 설정
  pinMode(LGND, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  digitalWrite(LGND, LOW);

  //엔코더 핀 모드 설정
  pinMode(EGND, OUTPUT);
  pinMode(VCC, OUTPUT);
  pinMode(SW, INPUT_PULLUP);
  pinMode(DT, INPUT_PULLUP);
  pinMode(CLK, INPUT_PULLUP);
  digitalWrite(VCC, HIGH);
  digitalWrite(EGND, LOW);

}

void loop() {
  int newA = digitalRead(DT);
  int newB = digitalRead(CLK);
  int sw = digitalRead(SW);
  brightness(newA, newB);
  colorselect(sw);

}
