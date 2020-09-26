#include <Servo.h>
int sw = 0;
int x = 0;
int unnamed = 0;

Servo servo_4;

void setup()
{
  pinMode(D2, INPUT);
  pinMode(D4, OUTPUT);
  servo_4.attach(D4);
  Serial.begin(9600);

}

void loop()
{
  sw = digitalRead(D2);
  if (sw == HIGH) {
    while (digitalRead(D2) == HIGH) {
      delay(1000); // Wait for 4 millisecond(s)
    }
    if (x == HIGH) {
      x = LOW;
    } else {
      x += HIGH;
    }
  }
  if (x == LOW) {
    servo_4.write(30);
    Serial.print("DEG:");
    Serial.println(servo_4.read());
    delay(1000); // Wait for 1000 millisecond(s)
  }
  if (x == HIGH) {
    servo_4.write(150);
    Serial.print("DEG:");
    Serial.println(servo_4.read());
    delay(2000); // Wait for 2000 millisecond(s)
    servo_4.write(30);
    Serial.print("DEG:");
    Serial.println(servo_4.read());
    delay(1000); // Wait for 1000 millisecond(s)
    x = LOW;
  }
}
