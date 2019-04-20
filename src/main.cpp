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
SoftwareSerial ble(BLE_TX, BLE_RX);

ConcreteVehicle vehicle(APIN1, APIN2, ENA, BPIN1, BPIN2, ENB);

void setup() {
    ble.begin(9600);
    Serial.begin(9600);
}

void loop() {
    while (ble.available()) {
        String c = ble.readStringUntil(';');
        Serial.println(c);
        vehicle.command(c);
    }
    vehicle.update();
    delay(20);
}
