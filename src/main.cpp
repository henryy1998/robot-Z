//
// Created by fulva on 4/12/19.
//

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <vehicle/ConcreteVehicle.h>

#define BLE_RX 4
#define BLE_TX 2
#define ENA 3
#define ENB 5
#define APIN1 7
#define APIN2 8
#define BPIN1 12
#define BPIN2 13
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
