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


//#define DEBUG
//SoftwareSerial ble(BLE_TX, BLE_RX);
int16_t params[5];
Vehicle vehicle;
unsigned long buffer{0};

CommandNode commandEnum[12]{
        {CommandRegistry::LEFT_MOTOR_AC,  "leftA"},
        {CommandRegistry::LEFT_MOTOR_SS,  "left"},
        {CommandRegistry::RIGHT_MOTOR_AC, "rightA"},
        {CommandRegistry::RIGHT_MOTOR_SS, "right"},
        {CommandRegistry::SERVO1A,        "servo1a"},
        {CommandRegistry::SERVO1SS,       "servo1"},
        {CommandRegistry::SERVO2A,        "servo2a"},
        {CommandRegistry::SERVO2_SS,      "servo2"},
        {CommandRegistry::SERVO2_RESET,   "servo2r"},
        {CommandRegistry::SERVO3A,        "servo3a"},
        {CommandRegistry::SERVO3_SS,      "servo3"},
        {CommandRegistry::SERVO3_RESET,   "servo3r"}
};


void setup() {
//    ble.begin(9600);
    Serial.begin(9600);
    auto *leftMotor = new MotorComt(APIN1, APIN2, ENA, CommandRegistry::LEFT_MOTOR_AC,
                                    CommandRegistry::LEFT_MOTOR_SS);
    auto *rightMotor = new MotorComt(BPIN1, BPIN2, ENB, CommandRegistry::RIGHT_MOTOR_AC,
                                     CommandRegistry::RIGHT_MOTOR_SS);
    auto *stepperComt2 = new StepperComt(48, STEPPER1_PIN4, STEPPER1_PIN2, STEPPER1_PIN3, STEPPER1_PIN1,
                                         CommandRegistry::SERVO2A, CommandRegistry::SERVO2_SS,
                                         CommandRegistry::SERVO2_RESET, 5.704, 500);
    auto *stepperComt3 = new StepperComt(48, STEPPER2_PIN4, STEPPER2_PIN2, STEPPER2_PIN3, STEPPER2_PIN1,
                                         CommandRegistry::SERVO3A, CommandRegistry::SERVO3_SS,
                                         CommandRegistry::SERVO3_RESET, 5.704, 500);
    auto *servoComt = new ServoComt(CommandRegistry::SERVO1SS, CommandRegistry::SERVO1A, SERVO_PIN, 90);
    vehicle.attachVehicleComt(*leftMotor);
    vehicle.attachVehicleComt(*rightMotor);
    vehicle.attachVehicleComt(*servoComt);
    vehicle.attachVehicleComt(*stepperComt2);
    vehicle.attachVehicleComt(*stepperComt3);
}

CommandRegistry resolveCommand(const String &ident) {
    for (const CommandNode &aCom:commandEnum) {
        if (aCom.ident == ident) {
            return aCom.command;
        }
    }
    return CommandRegistry::NULLCOMMAND;
}

void reorder(int16_t *array, uint8_t length) {
    const int finalIndex = length / 2;
    for (uint8_t i = 0; i < finalIndex; i++) {
        int16_t swap = array[i];
        const int j = length - i - 1;
        array[i] = array[j];
        array[j] = swap;
    }
}

void loop() {
    while (Serial.available() > 0) {
        static char c[20];
        static uint8_t index(0);
        char next = Serial.read();
        while (next != -1 && next != ';' && index < 20 - 1) {
            c[index] = next;
            next = Serial.read();
            index += 1;
        }
        c[index] = '\0';
        if (next == ';') {
            index = 0;
            String command(c);
#ifdef DEBUG
            Serial.println(c);
            Serial.println(command);
#endif
            uint8_t count(0);
            int i;
            while ((i = command.lastIndexOf(":")) != -1) {
                params[count++] = command.substring(static_cast<unsigned int>(i + 1)).toInt();
#ifdef DEBUG
                Serial.println(command.substring(i + 1));
#endif
                command = command.substring(0, static_cast<unsigned int>(i));
            }
#ifdef DEBUG
            Serial.println(command);
#endif

            CommandRegistry registry = resolveCommand(command);

            if (registry != CommandRegistry::NULLCOMMAND) {
                reorder(params, count);
                vehicle.command(registry, params);
            }
        }


    }
    if (millis() > 50 * buffer) {
        vehicle.command(CommandRegistry::LEFT_MOTOR_AC, nullptr);
        vehicle.command(CommandRegistry::RIGHT_MOTOR_AC, nullptr);
        vehicle.command(CommandRegistry::SERVO1A, nullptr);
//#ifdef DEBUG
//        Serial.print("cycle:");
//        Serial.println(buffer);
//#endif
        buffer++;
    }
    vehicle.command(CommandRegistry::SERVO2A, nullptr);
    vehicle.command(CommandRegistry::SERVO3A, nullptr);
}
