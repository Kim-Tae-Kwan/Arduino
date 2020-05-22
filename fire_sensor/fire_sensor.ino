#define fire A0
#define GND A1
#define VCC A2
#define BGND 5
#define BUZZER 3


void setup() {
  Serial.begin(9600);

  pinMode(fire, INPUT);
  pinMode(VCC, OUTPUT);
  pinMode(GND, OUTPUT);
  digitalWrite(VCC, HIGH);
  digitalWrite(GND, LOW);


  pinMode(BGND, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BGND, LOW);

}

void loop() {

  int val = analogRead(fire);
  int fire_a = map(val, 0, 1023, 0, 255);

  if (fire_a < 100) {

    Serial.print("화재발생!!!  ");
    

    
      for (int i = 300; i < 750; i++)
      {
        tone(BUZZER, i);
        delay(5);
      }
      
      for (int i = 750; i> 300; i--)
      {
        tone(BUZZER, i);
        delay(5);
      }

      
      
      noTone(BUZZER);
    
  }


  delay(500);





}
