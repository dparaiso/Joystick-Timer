/**
 * File includes led logic, initializing and checking joystick values
*/
#include "hal/led.h"
#include <stdio.h>
#include <stdlib.h>


void led_init(){
    ledWrite(LED_TRIG0, "none");
    ledWrite(LED_TRIG1, "none");
    ledWrite(LED_TRIG2, "none");
    ledWrite(LED_TRIG3, "none");
}

void ledWrite(char *filename, char *param){
    FILE *pLedTriggerFile = fopen(filename, "w");
    if(pLedTriggerFile == NULL){
        printf("ERROR: Unable to open file (%s) for read\n", filename);
        exit(1);
    }

    int charWritten = fprintf(pLedTriggerFile, param);
    if(charWritten <= 0){
        printf("ERROR WRITING DATA\n");
        exit(1);
    }

    fclose(pLedTriggerFile);
}