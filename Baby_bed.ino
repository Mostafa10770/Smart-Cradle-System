// led 4 v7, rain 34 v0, mic 35 v1
// based on blynk platform. this IOT project aims to help parents monitoring the baby behavior.
#define BLYNK_TEMPLATE_ID "TMPL2lSpqPBli"
#define BLYNK_TEMPLATE_NAME "BABY"
#define BLYNK_AUTH_TOKEN "NHx99pUkNZyDwc6K2OhSSCQaHA3vTea0"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Mostafa";
char pass[] = "91576811";

BlynkTimer timer;

BLYNK_WRITE(V7)
{
  int pinValue = param.asInt();
  digitalWrite(4,pinValue);
}

void mic()
{
  int mic = analogRead(35); 
  Serial.print("Mic");
  Serial.println(mic);
  Blynk.virtualWrite(V1, mic);
}

void rain()
{
  float rainread = analogRead(34); 
  int x = 4095 - rainread; 
  Serial.println(x);
  Blynk.virtualWrite(V0, x);
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, mic);
  timer.setInterval(2000L, rain);
  pinMode(4, OUTPUT);
}
//run blink and timer
void loop() {
  Blynk.run();
  timer.run();
}
