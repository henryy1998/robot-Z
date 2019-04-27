//
// Created by fulva on 4/12/19.
//

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <vehicle/ConcreteVehicle.h>

#define BLE_RX 4 //connect the pin with bluetooth rx pin
#define BLE_TX 2 //connect the pin with bluetooth tx pin
#define ENA 3 //connect to l298n ENA
#define ENB 5 //connect to l298n ENB
#define APIN1 7 //connect to l298n pin1
#define APIN2 8 //connect to l298n pin2
#define BPIN1 12 //connect to l298n pin3
#define BPIN2 13 //connect to l298n pin4
#define SERVO_PIN 9
#define STEPPER1_PIN1 A0
#define STEPPER1_PIN2 A1
#define STEPPER1_PIN3 A2
#define STEPPER1_PIN4 A3
#define STEPPER2_PIN1 A4
#define STEPPER2_PIN2 A5
#define STEPPER2_PIN3 10
#define STEPPER2_PIN4 11
#define DEBUG
SoftwareSerial ble(BLE_TX, BLE_RX);
int16_t params[5];
ConcreteVehicle vehicle(APIN1, APIN2, ENA, BPIN1, BPIN2, ENB, SERVO_PIN,
                        Stepper(48, STEPPER1_PIN4, STEPPER1_PIN2, STEPPER1_PIN3, STEPPER1_PIN1),
                        Stepper(48, STEPPER2_PIN1, STEPPER2_PIN2, STEPPER2_PIN3, STEPPER2_PIN4));

void setup() {
    ble.begin(9600);
    Serial.begin(9600);
}

void loop() {
    while (ble.available()) {
        String c = ble.readStringUntil(';');
        uint8_t count(0);
        int i;
        while ((i = c.lastIndexOf(":")) != -1) {
            params[count++] = c.substring(i + 1).toInt();
            Serial.println(c.substring(i + 1));
            c = c.substring(0, i);
        }
        Serial.println(c);
        vehicle.command(c, params);
    }
    vehicle.command("leftA", nullptr);
    vehicle.command("rightA", nullptr);
    vehicle.command("servo1a", nullptr);
    vehicle.command("servo2a", nullptr);
    delay(50);
}
