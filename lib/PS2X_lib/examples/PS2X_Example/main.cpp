//
// Created by fulva on 4/12/19.
//

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <vehicle/vehiclecomponent/MotorComt.h>
#include <vehicle/vehiclecomponent/ServoComt.h>
#include <vehicle/vehiclecomponent/StepperComt.h>
#include <vehicle/Vehicle.h>
#include <vehicle/vehiclecomponent/ServoComt.h>
#include "PinConfig.h"
#include <Encoder.h>

#define SENSOR_1_1 3
#define SENSOR_1_2 4

Encoder test(SENSOR_1_1,SENSOR_1_2);

void setup() {
Serial.begin(9600);
}

void loop() {
Serial.println(test.read());
}
