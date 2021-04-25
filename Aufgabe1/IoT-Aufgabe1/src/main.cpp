#include <Arduino.h>
#include <WiFi.h>

const int LED = 21;
const int touch0 = 4;
const int touch1 = 0;
const int touch2 = 2;

const char* ssid = "Test_Access-Point";
const char* password = "test";

WiFiServer server(80);

String header;

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(touch0, INPUT);

  //Access-Point
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.println("IP-Adress");
  Serial.println(IP);
  server.begin();
}

void loop() {
  //Access-Point
  WiFiClient client = server.available();
  if(client){
    Serial.println("New User!");

  if(client.connected()){
      client.println("<!DOCTYPE html><html><head><title>Testpage</title></head><body><p>Hello World!</p></body></html>");
  }
    
  }
  //Touch Sensor Test
  Serial.println(digitalRead(touch0));
  if(digitalRead(touch0) == 1){
    Serial.println("Worked");
  }
  delay(1000);
  //LED-Blink
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);
  }