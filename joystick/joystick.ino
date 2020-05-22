#define GND A0
#define VCC A1
#define X A2
#define Y A3
#define SW A4

#define LGND 8
#define G 9
#define R 10
#define B 11

int color = G;
int i = 0;

void light(int x , int y , int sw)
{
  analogWrite(R, x);
  analogWrite(G, y);

  if (sw == 0) digitalWrite(B, HIGH);
  else digitalWrite(B, LOW);

}
/* 색 변화시키기
  void change(int y)
  {

  if (y > 100)
  {
    delay(500);
    digitalWrite(color++, LOW);
    if (color > 11) color = G;
    digitalWrite(color, HIGH);
  }
  else if (y < 30)
  {
    delay(500);
    digitalWrite(color--, LOW);
    if (color < 9) color = B;
    digitalWrite(color, HIGH);
  }

  }
*/

//숫자 변화 시키기
void change(int y, int sw)
{

  if (y > 100)
  {
    i++;
    if (i > 100) i = 100;
    Serial.print("정수 값 : ");
    Serial.println(i);
    
  }
  else if (y < 30)
  {
    i--;
    if (i < 0) i = 0;
    Serial.print("정수 값 : ");
    Serial.println(i);
    
  }
  else if (sw == 0) 
  {
    i = 0;
    Serial.print("정수 값 : ");
    Serial.println(i);
    
  }
}


void setup() {

  Serial.begin(115200);
  pinMode(GND, OUTPUT);
  pinMode(VCC, OUTPUT);
  pinMode(X, INPUT_PULLUP);
  pinMode(Y, INPUT_PULLUP);
  pinMode(SW, INPUT_PULLUP);
  digitalWrite(GND, LOW);
  digitalWrite(VCC, HIGH);

  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(LGND, OUTPUT);
  digitalWrite(LGND, LOW);
}

void loop() {
  int x = map(analogRead(X), 0, 1023, 0, 128);
  int y = map(analogRead(Y), 0, 1023, 0, 128);
  int sw = digitalRead(SW);

  //light(x,y,sw);


  change(y,sw);
  delay(150);




  /*
    Serial.print("X축 : ");
    Serial.print(x);
    Serial.print("\t");

    Serial.print("Y축 : ");
    Serial.print(y);
    Serial.print("\t");

    Serial.print("스위치 : ");
    Serial.println(sw);
  */
}
