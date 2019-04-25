//
// Created by fulva on 4/12/19.
//

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <vehicle/ConcreteVehicle.h>

#define BLE_RX 13 //connect the pin with bluetooth rx pin
#define BLE_TX 12 //connect the pin with bluetooth tx pin
#define ENA 3 //connect to l298n ENA
#define ENB 5 //connect to l298n ENB
#define APIN1 2 //connect to l298n pin1
#define APIN2 4 //connect to l298n pin2
#define BPIN1 7 //connect to l298n pin3
#define BPIN2 6 //connect to l298n pin4
#define DEBUG
SoftwareSerial ble(BLE_TX, BLE_RX);
int16_t params[5];
ConcreteVehicle vehicle(APIN1, APIN2, ENA, BPIN1, BPIN2, ENB, 0);

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
    vehicle.update();
    delay(50);
}
