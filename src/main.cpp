//
// Created by fulva on 4/12/19.
//

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <vehicle/ConcreteVehicle.h>
#include <vehicle/vehiclecomponent/MotorComt.h>
#include <vehicle/vehiclecomponent/ServoComt.h>
#include <vehicle/vehiclecomponent/StepperComt.h>
#include <vehicle/Vehicle.h>

#define BLE_RX 4 //connect the pin with bluetooth rx pin
#define BLE_TX 2 //connect the pin with bluetooth tx pin
#define ENA 3 //connect to l298n ENA, connect to left motor
#define ENB 5 //connect to l298n ENB, connect to right motor
#define APIN1 7 //connect to l298n pin1, connect to left motor
#define APIN2 8 //connect to l298n pin2, connect to left motor
#define BPIN1 12 //connect to l298n pin3, connect to right motor
#define BPIN2 13 //connect to l298n pin4, connect to right motor
#define SERVO_PIN 11
#define STEPPER1_PIN1 A0
#define STEPPER1_PIN2 A1
#define STEPPER1_PIN3 A2
#define STEPPER1_PIN4 A3
#define STEPPER2_PIN1 A4
#define STEPPER2_PIN2 A5
#define STEPPER2_PIN3 10
#define STEPPER2_PIN4 9
#define DEBUG
SoftwareSerial ble(BLE_TX, BLE_RX);
int16_t params[5];
const String LEFT_MOTOR_AC{"leftA"};
const String RIGHT_MOTOR_AC{"rightA"};
const String LEFT_MOTOR_SS{"left"};
const String RIGHT_MOTOR_SS{"right"};
Vehicle vehicle;
unsigned long buffer{0};


void setup() {
    ble.begin(9600);
    Serial.begin(9600);
    MotorComt *leftMotor = new MotorComt(APIN1, APIN2, ENA, LEFT_MOTOR_AC, LEFT_MOTOR_SS);
    MotorComt *rightMotor = new MotorComt(BPIN1, BPIN2, ENB, RIGHT_MOTOR_AC, RIGHT_MOTOR_SS);
    StepperComt *stepperComt2 = new StepperComt(48, STEPPER1_PIN4, STEPPER1_PIN2, STEPPER1_PIN3, STEPPER1_PIN1,
                                                "servo2a", "servo2",
                                                "servo2r", 11, 500);
    StepperComt *stepperComt3 = new StepperComt(48, STEPPER2_PIN4, STEPPER2_PIN2, STEPPER2_PIN3, STEPPER2_PIN1,
                                                "servo3a", "servo3",
                                                "servo3r", 11, 500);
    ServoComt *servoComt = new ServoComt("servo1", SERVO_PIN);
    vehicle.attachVehicleComt(*leftMotor);
    vehicle.attachVehicleComt(*rightMotor);
    vehicle.attachVehicleComt(*servoComt);
    vehicle.attachVehicleComt(*stepperComt2);
    vehicle.attachVehicleComt(*stepperComt3);
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
//    if (millis() > 50 * buffer) {
//        vehicle.command(LEFT_MOTOR_AC, nullptr);
//        vehicle.command(RIGHT_MOTOR_AC, nullptr);
//        buffer++;
//    }
//    vehicle.command("servo2a", nullptr);
//    vehicle.command("servo3a", nullptr);
}
