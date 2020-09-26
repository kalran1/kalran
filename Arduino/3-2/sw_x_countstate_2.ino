#include <ESP8266WiFi.h>
int x = 0;
int sw = 0;
int count = 0;
int countstate = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(4, INPUT);
  pinMode(2, OUTPUT);
}

void loop()
{
  sw = digitalRead(4);
  if (sw == HIGH) {
    
    Serial.println(count);
    while ( digitalRead(4) == HIGH) {
      delay(5); // Wait for 5 millisecond(s)
    }
    if (x == HIGH) {
      x = LOW;
      count++;
    countstate++;
    } else {
      x = HIGH;
      count++;
    countstate++;
    }
  }
  if (countstate%2==0) {
    digitalWrite(2,HIGH);
  } else {
    digitalWrite(2,LOW);
  }
  
  delay(10); // Wait for 10 millisecond(s)
 
}
