//
// Created by fulva on 4/12/19.
//

#include <Arduino.h>
#include <SoftwareSerial.h>

#define BLE_RX 3
#define BLE_TX 2
SoftwareSerial ble(BLE_TX, BLE_RX);

void setup() {
    ble.begin(9600);
    Serial.begin(9600);
}

void loop() {
    if (ble.available()) {
        String c = ble.readStringUntil(';');
        Serial.println(c);
    }
}
