#include <Arduino.h>

#define SWITCH_PIN 2
byte incByte;

void setup() {
    Serial.begin(9600);
    pinMode(SWITCH_PIN, OUTPUT);
    // включить первый выход
    digitalWrite(SWITCH_PIN, HIGH);
}

void loop() {
    if (Serial.available()) {
        incByte = Serial.read();
        if (incByte == '1') {
            digitalWrite(SWITCH_PIN, HIGH);
            Serial.println("Selected port: 1");
        } else if (incByte == '2') {
            digitalWrite(SWITCH_PIN, LOW);
            Serial.println("Selected port: 2");
        }
    }
}