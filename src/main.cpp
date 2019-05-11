//
// Created by fulva on 4/12/19.
//

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <vehicle/vehiclecomponent/MotorComt.h>
#include <vehicle/vehiclecomponent/ServoComt.h>
#include <vehicle/vehiclecomponent/StepperComt.h>
#include <vehicle/Vehicle.h>
#include "PinConfig.h"


//#define DEBUG
SoftwareSerial ble(BLE_TX, BLE_RX);
int16_t params[5];
const String LEFT_MOTOR_AC{"leftA"};
const String RIGHT_MOTOR_AC{"rightA"};
const String LEFT_MOTOR_SS{"left"};
const String RIGHT_MOTOR_SS{"right"};
const String SERVO_AC{"servo1A"};
Vehicle vehicle;
unsigned long buffer{0};


void setup() {
    ble.begin(9600);
    Serial.begin(9600);
    MotorComt *leftMotor = new MotorComt(APIN1, APIN2, ENA, LEFT_MOTOR_AC, LEFT_MOTOR_SS);
    MotorComt *rightMotor = new MotorComt(BPIN1, BPIN2, ENB, RIGHT_MOTOR_AC, RIGHT_MOTOR_SS);
    StepperComt *stepperComt2 = new StepperComt(48, STEPPER1_PIN4, STEPPER1_PIN2, STEPPER1_PIN3, STEPPER1_PIN1,
                                                "servo2a", "servo2",
                                                "servo2r", 5.704, 500);
    StepperComt *stepperComt3 = new StepperComt(48, STEPPER2_PIN4, STEPPER2_PIN2, STEPPER2_PIN3, STEPPER2_PIN1,
                                                "servo3a", "servo3",
                                                "servo3r", 5.704, 500);
    ServoComt *servoComt = new ServoComt("servo1", SERVO_AC, SERVO_PIN, 130);
    vehicle.attachVehicleComt(*leftMotor);
    vehicle.attachVehicleComt(*rightMotor);
    vehicle.attachVehicleComt(*servoComt);
    vehicle.attachVehicleComt(*stepperComt2);
    vehicle.attachVehicleComt(*stepperComt3);
}

void loop() {
    while (ble.available()) {
        char c[20];
        uint8_t index(0);
        char next = ble.read();
        while (next != -1 && next != ';' && index < 20 - 1) {
            c[index] = next;
            next = ble.read();
            index += 1;
        }
        c[index] = '\0';
        if (next == ';') {
            String command{c};
#ifdef DEBUG
            Serial.println(c);
            Serial.println(command);
#endif
            uint8_t count(0);
            int i;
            while ((i = command.lastIndexOf(":")) != -1) {
                params[count++] = command.substring(i + 1).toInt();
#ifdef DEBUG
                Serial.println(command.substring(i + 1));
#endif
                command = command.substring(0, i);
            }
#ifdef DEBUG
            Serial.println(command);
#endif
            vehicle.command(command, params);
        }


    }
    if (millis() > 50 * buffer) {
        vehicle.command(LEFT_MOTOR_AC, nullptr);
        vehicle.command(RIGHT_MOTOR_AC, nullptr);
        vehicle.command(SERVO_AC, nullptr);
        buffer++;
    }
    vehicle.command("servo2a", nullptr);
    vehicle.command("servo3a", nullptr);
}
