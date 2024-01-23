// Sample button module 
// Part of the Hardware Abstraction Layer (HAL) 

#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_

#include <stdbool.h>

#define LEFT "config-pin p8.18 gpio"
#define RIGHT "config-pin p8.15 gpio"
#define UP "config-pin p8.14 gpio"
#define DOWN "config-pin p8.17 gpio"

int readFromFileToScreen(char* fileName);
void button_init(void);
bool button_is_button_pressed(void);
void button_cleanup(void);
bool responseLeftRight();

#endif