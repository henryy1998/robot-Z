//
// Created by Fulva on 5/10/2019.
//

#ifndef ROBOT_Z_PINCONFIG_H
#define ROBOT_Z_PINCONFIG_H

#define BLE_RX 11 //connect the pin with bluetooth rx pin
#define BLE_TX 10 //connect the pin with bluetooth tx pin
#define ENA 6 //connect to l298n ENA, connect to left motor
#define ENB 5 //connect to l298n ENB, connect to right motor
#define APIN1 8 //connect to l298n pin1, connect to left motor
#define APIN2 7 //connect to l298n pin2, connect to left motor
#define BPIN1 2 //connect to l298n pin3, connect to right motor
#define BPIN2 4 //connect to l298n pin4, connect to right motor
#define STBY 3 //always give high as the current design
#define SERVO_PIN 9

#define STEPPER1_PIN1 12
#define STEPPER1_PIN2 13
#define STEPPER1_PIN3 A0
#define STEPPER1_PIN4 A1

#define STEPPER2_PIN1 A2
#define STEPPER2_PIN2 A3
#define STEPPER2_PIN3 A4
#define STEPPER2_PIN4 A5

#endif //ROBOT_Z_PINCONFIG_H
