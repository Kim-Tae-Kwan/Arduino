#define GND 5
#define S 3
#define C 261.6256  //도c
#define D 293.6648  //레d
#define E 329.6276  //미e
#define F 349.2282  //파f
#define G 391.9954  //솔g
#define A 440.0  //라a
#define B 493.8833  //시b
#define C5 523.2511  //도c5

float san[] = {G, E, E, G, E, C, D, E, D, C, E, G};
float eng[] = {0,C,D,E,F,G,A,B};
char kor[]={' ','도','레','미','파','솔','라','시'};

void santo() {
  for (int i = 0; i < 13; i++)
  {
    tone(S, san[i]);
    delay(500);
  }
  noTone(S);
}

void ton_a(int eum){
  tone(S, eng[eum]);
  Serial.println(kor[eum]);
  delay(300);
}

void setup() {
  Serial.begin(9600);
  pinMode(GND, OUTPUT);
  pinMode(S, OUTPUT);
  digitalWrite(GND, LOW);

}


void loop() {

  while (Serial.available() > 0) {

    char a = Serial.read();


    switch (a) {
      case '1':
        ton_a(a);
        break;
      case '2':
        ton_a(a);
        break;
      case '3':
        ton_a(a);
        break;
      case '4':
        ton_a(a);
        break;
      case '5':
        ton_a(a);
        break;
      case '6':
        ton_a(a);
        break;
      case '7':
        ton_a(a);
        break;
    }
    


  }




}
