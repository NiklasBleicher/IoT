#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include "webapp.h"

const int LED = 21;
const int touch0 = 4;
const int touch1 = 0;
const int touch2 = 2;

const char* ssid = "Test_Access-Point";
const char* password = "test";

WebServer server(80);

String header;

void handleRoot(){
    String html = webappIndex;
    server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);

  //pin Modes for Buttons
  pinMode(LED, OUTPUT);
  pinMode(touch0, INPUT);
  pinMode(touch1, INPUT);
  pinMode(touch2, INPUT);

  //Access-Point
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
    
  //Touch Sensor Test
  Serial.println(digitalRead(touch0));
  if(digitalRead(touch0) == 1){
    Serial.println("Worked");
  }
  delay(1000);

  /*LED-Blink
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);*/
  }