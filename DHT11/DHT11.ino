#include <DHT.h>
#define S A0
#define VCC A1
#define GND A2
#define DHTTYPE DHT11

DHT dht(S, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(S, INPUT);
  pinMode(VCC, OUTPUT);
  pinMode(GND, OUTPUT);
  digitalWrite(VCC, HIGH);
  digitalWrite(GND, LOW);


}

void loop() {
  // delay(1000);
  float fT = dht.readTemperature();
  float fH = dht.readHumidity();
  if (isnan(fT) || isnan(fH)) {
    Serial.println("Failed to read form DHT");
  }
  else{
  Serial.print("TEMP : ");
  Serial.print(fT);
  Serial.print("[C]\t ");
  Serial.print("HUMI : ");
  Serial.print(fH);
  Serial.println("[%]");
  }

}
