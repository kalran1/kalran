#include <Servo.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "iptimewoorijip";
const char* pass = "ssw96385271**";

ESP8266WebServer server(80);
Servo myservo;

void setup(void){

  Serial.begin(19200);
  Serial.println("연결 하는 중입니다....");
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
}

  Serial.println("");
  Serial.print("할당 IP");
  Serial.println(ssid);
  Serial.print("IP 주소 : ");
  Serial.println(WiFi.localIP());

  server.on("/", [](){
    
    server.send(200, "text/html", "<!DOCTYPE html> <html lang=\"ko\"></html> <head> <title>41515092 서유원</title> <style> .button1{ background-color : #00000000; text-decoration : none; text-align : center; font-size : 15px; width : 50px; height : 22.5px; color : rgb(0, 0, 0); padding : 15px 15px; margin : 3px 2px; cursor : pointer; display : inline-block; } .button2{ background-color : #000000; text-decoration : none; text-align : center; font-size : 15px; width : 50px; height : 22.5px; color : rgb(255, 254, 254); padding : 15px 15px; margin : 2px 2px; cursor : pointer; display : inline-block; } </style> </head> <body><center> <h3>애완동물 자동급식</h3> <a href=\"/on\" class=\"button1\"> ON </a> <a href=\"/off\" class=\"button2\"> OFF </a> </center></body> </html>");  
    });

  server.on("/on", [](){

    Serial.println("ON");
    myservo.write(180);
    delay(1000);
    myservo.write(0);
    server.send(200, "text/html", "<!DOCTYPE html> <html lang=\"ko\"></html> <head> <title>41515092 서유원</title> <style> .button1{ background-color : #00000000; text-decoration : none; text-align : center; font-size : 15px; width : 50px; height : 22.5px; color : rgb(0, 0, 0); padding : 15px 15px; margin : 3px 2px; cursor : pointer; display : inline-block; } .button2{ background-color : #000000; text-decoration : none; text-align : center; font-size : 15px; width : 50px; height : 22.5px; color : rgb(255, 254, 254); padding : 15px 15px; margin : 2px 2px; cursor : pointer; display : inline-block; } </style> </head> <body><center> <h3>애완동물 자동급식</h3> <a href=\"/on\" class=\"button1\"> ON </a> <a href=\"/off\" class=\"button2\"> OFF </a> </center></body> </html>");  
    });

  server.begin();
  Serial.println("HTTP server started");
  myservo.attach(D4);   // Servo attached to D4 pin
  myservo.write(0);
}

void loop(void){
  server.handleClient();
}
