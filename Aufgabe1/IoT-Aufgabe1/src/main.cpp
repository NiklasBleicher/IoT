#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include "webapp.h"

const int LEDEasy = 21;
const int LEDMedium = 0;
const int LEDHard = 0;
const int touch0 = 4;
const int touch1 = 0;
const int touch2 = 2;

const char* ssid = "Test_Access-Point";
const char* password = "test";

WebServer server(80);

void handleRoot(){
    String html = webappIndex;
    server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);

  //pin Modes for Buttons
  pinMode(LEDEasy, OUTPUT);
  pinMode(touch0, INPUT); //Button Easy
  pinMode(touch1, INPUT); //Button Medium
  pinMode(touch2, INPUT); //Button Hard

  //Access-Point Settings
  WiFi.softAP(ssid, password);
  String html = webappIndex;
  server.on("/", handleRoot);

  //Get IP
  IPAddress IP = WiFi.softAPIP();
  Serial.println("IP-Adress");
  Serial.println(IP);
  server.begin();
}

void loop() {
  //Access-Point
  server.handleClient();

  //Change Hosted Page when Button pressed

    
  /*Touch Sensor Test
  Serial.println(digitalRead(touch0));
  if(digitalRead(touch0) == 1){
    Serial.println("Worked");
  }
  delay(1000);*/

  /*LED-Blink
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);*/
  
  }