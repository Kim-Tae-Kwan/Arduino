#define L 9
#define S 10
#define VCC 11
#define GND 12
int light = 0;

#define L2 6
#define S2  5
#define VCC2 4
#define GND2 3
int light2 = 0;

void magic1(int val)
{
  if (val == 0)
  {
    light -= 5;
    if (light < 0) light = 0;
    analogWrite(L, light);
    
    
  }
  else if (val == 1) {
    light += 5;
    if (light > 255) light = 255;
    analogWrite(L, light);
    
    
  }
}

void magic2(int val)
{
  if (val == 0)
  {
    light2 -= 5;
    if (light2 < 0) light2 = 0;
    analogWrite(L2, light2);
    
    
  }
  else if (val == 1) {
    light2 += 5;
    if (light2 > 255) light2 = 255;
    analogWrite(L2, light2);
    
    
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(L, OUTPUT);
  pinMode(S, INPUT);
  pinMode(VCC, OUTPUT);
  pinMode(GND, OUTPUT);

  digitalWrite(VCC, HIGH);
  digitalWrite(GND, LOW);

  pinMode(L2, OUTPUT);
  pinMode(S2, INPUT);
  pinMode(VCC2, OUTPUT);
  pinMode(GND2, OUTPUT);

  digitalWrite(VCC2, HIGH);
  digitalWrite(GND2, LOW);

}

void loop() {
  int val = digitalRead(S);
  int val2 = digitalRead(S2);
  magic2(val2);

  

  
  magic1(val);



  
    Serial.print("light 1 : ");
    Serial.print(light);
    Serial.print("   ");
    Serial.print("light 2 : ");
    Serial.println(light2);
  

}
