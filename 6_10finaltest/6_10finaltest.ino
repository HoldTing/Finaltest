#include <Ultrasonic.h>
#include <LWiFi.h>
#include <WiFiClient.h>
#include "MCS.h"
#define _SSID "AA202_2G"
#define _KEY  "iteaa202"

Ultrasonic ultrasonic(12, 13);
int distance;
MCSDevice mcs("Ddkp21B6", "xz3X2o8iCOU8Dikf");
MCSDisplayInteger Distance("Distance");
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  Serial.println(F("Ultrasonicxx test!"));

  while(WL_CONNECTED != WiFi.status())
  {
    Serial.print("WiFi.begin(");
    Serial.print(_SSID);
    Serial.print(",");
    Serial.print(_KEY);
    Serial.println(")...");
    WiFi.begin(_SSID, _KEY);
  }
  Serial.println("WiFi connected !!");

  mcs.addChannel(Distance);

  while(!mcs.connected())
  {
    Serial.println("MCS.connect()...");
    mcs.connect();
  }
  Serial.println("MCS connected !!");
}

void loop() {
  distance = ultrasonic.read();
  
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  Distance.set(distance);
  delay(1000);
}
