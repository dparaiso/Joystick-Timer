#include "hal/joystick.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 

// Allow module to ensure it has been initialized (once!)
static bool is_initialized = false;

int readFromFileToScreen(char* fileName)
{
    FILE *pFile = fopen(fileName, "r");
    if (pFile == NULL) {
    printf("ERROR: Unable to open file (%s) for read\n", fileName);
    exit(-1);
    }
    // Read string (line)
    const int MAX_LENGTH = 1024;
    char buff[MAX_LENGTH];
    fgets(buff, MAX_LENGTH, pFile);
    // Close
    fclose(pFile);
    return buff[0] - '0';
}

void button_init(void) 
{
    printf("Button - Initializing\n");
    assert(!is_initialized);
    is_initialized = true;

    srand(time(0));
}

bool button_is_button_pressed(void)
{
    assert(is_initialized);

    // Read the button state (no, don't just randomly get a value!)
    bool is_pressed = rand() % 2;
    return is_pressed;

}
void button_cleanup(void)
{
    // Free any memory, close files, ...
    printf("Button - Cleanup\n");
    assert(is_initialized);
    is_initialized = false;
}


bool responseLeftRight()
{
    if(readFromFileToScreen(LEFT) == 0 || readFromFileToScreen(RIGHT) == 0){
        return true; 
    }
    return false; 
}
