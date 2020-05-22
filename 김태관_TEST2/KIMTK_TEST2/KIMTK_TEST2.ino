int menu = 0;
int br=0;
int x = 0;
int y = 0;
int sw = 0;

//== 조이스틱 ==================================
#define X  A0
#define Y  A1
#define SW 2
//=============================================

// == 1. Melody================================
#define BGND 7
#define BS   4
#define C 262 // 도 
#define D 294 // 레 
#define E 330 // 미 
#define F 349 // 파 
#define G 392 // 솔 
#define A 440 // 라 
#define B 494 // 시 

int tempo = 200; // duration 옵션 값 설정
int notes[25] = { G, G, A, A, G, G, E, G, G, E, E, D, G, G, A, A, G, G, E, G, E, D, E, C };

void Melody()
{
  
  for (int i = 0; i < 12; i++) {
    
    delay (300);
    if(br==1) {
      menu=5;
      break;
    }
    tone (BS, notes[ i ], tempo);
    
  }
  delay(100); // 멜로디 중간에 짧게 멈추는 용도

  for (int i = 12; i < 25; i++) {
     
    delay (300);
    if(br==1) {
      menu=5;
      break;
    }
    tone (BS, notes[ i ], tempo);
    
  }
  br=0;
  noTone(BS);

}
//=============================================

//== 2. Moodlight =============================
#define MGND 8
#define MS   9

void Moodlight()
{
  digitalWrite(MS, HIGH);
}
//=============================================

//== 3. Security ==============================
#define Security_OUT 10
#define Security_VCC 11
#define Security_GND 12

void Security()
{
  int SS = digitalRead(Security_OUT);
  if (SS == 1)
  {
    for (int i = 300; i <= 750; i++)
    {
      tone(BS, i);
      delay(1);
    }
    for (int i = 750; i >= 300; i--)
    {
      tone(BS, i);
      delay(1);
    }
  }
  noTone(BS);
}
//===========================================

//== 4. Streetlamp ============================
#define JS A2 // 조도센서
#define JGND 13 // LED
#define JLED 3
#define JLED2 5
#define JLED3 6

void Streetlamp()
{
  int js = map(analogRead(JS), 0, 1023, 0, 50);
  analogWrite(JLED, js);
  analogWrite(JLED2, js);
  analogWrite(JLED3, js);
}
//==============================================

void setting()
{
  digitalWrite(MS, LOW);
  analogWrite(JLED, 0);
  analogWrite(JLED2, 0);
  analogWrite(JLED3, 0);
  
}

void setup() {                                  //<------------ setup()
  attachInterrupt(0, blink, FALLING);


  //== 시작 ==================================

  Serial.begin(9600);
  Serial.println(" ++++ Menu +++");
  Serial.println("1. Left - Melody");
  Serial.println("2. Right - Moodilght");
  Serial.println("3. Up - Security");
  Serial.println("4. Down - Streetlamp");
  Serial.println("5. push S/W - STOP");
  Serial.println();
  //=========================================

  //== 조이스틱 핀모드 ========================
  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  pinMode(SW, INPUT_PULLUP);
  //=========================================

  // ==1. Melody ============================
  pinMode(BGND, OUTPUT);
  pinMode(BS, OUTPUT);
  digitalWrite(BGND, LOW);
  //=========================================

  //==2. Moodlight ==========================
  pinMode(MGND, OUTPUT);
  pinMode(MS, OUTPUT);
  digitalWrite(MGND, LOW);
  //=========================================

  //==3. Security ===========================
  pinMode(Security_VCC, OUTPUT);
  pinMode(Security_GND, OUTPUT);
  pinMode(Security_OUT, INPUT_PULLUP);
  digitalWrite(Security_VCC, HIGH);
  digitalWrite(Security_GND, LOW);
  //=========================================

  // ==4. Streetlamp ========================
  pinMode(JS, INPUT_PULLUP);
  pinMode(JGND, OUTPUT);
  pinMode(JLED, OUTPUT);
  digitalWrite(JGND, LOW);
  //=========================================

}

void loop() {                                    // <------------ loop()
  x = map(analogRead(X), 0, 1023, 0, 100);
  y = map(analogRead(Y), 0, 1023, 0, 100);
  sw = digitalRead(SW);

  if (x < 25 ) menu = 1;
  else if (x > 70 ) menu = 2;
  else if (y < 25 ) menu = 3;
  else if (y > 70 ) menu = 4;
  else if (sw == 0)  menu = 5;

  switch (menu) {
    case 1:
      Melody();
      break;
    case 2:
      Moodlight();
      break;
    case 3:
      Security();
      break;
    case 4:
      Streetlamp();
      break;
    case 5:
      setting();
      menu=5;
      break;

  }
}

// == 인터럽트 =================================
void blink()
  {
    sw = digitalRead(SW);
    if(sw==0) br=1;
  
  }
//=============================================
