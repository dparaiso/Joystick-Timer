// Sample button module 
// Part of the Hardware Abstraction Layer (HAL) 

#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_

#include <stdbool.h>

#define LEFT "config-pin p8.18 gpio"
#define RIGHT "config-pin p8.15 gpio"
#define UP "config-pin p8.14 gpio"
#define DOWN "config-pin p8.17 gpio"

#define LEFT_FILE "/sys/class/gpio/gpio65/value"
#define RIGHT_FILE "/sys/class/gpio/gpio47/value"
#define UP_FILE "/sys/class/gpio/gpio26/value"
#define DOWN_FILE "/sys/class/gpio/gpio46/value"

int readFromFileToScreen(char *fileName);
void joystick_init(void);
int response(void);
bool checkResponse(int targetDirection, int chosenDirection);

#endif