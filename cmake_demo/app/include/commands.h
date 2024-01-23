// Sample application module
// Normally, you might create a module such as this for each module in
// the application that does some high-level task; perhaps has its own thread.

#ifndef _COMMANDS_H_
#define _COMMANDS_H_
#include <stdio.h> 
#include <time.h> 
#include <stdlib.h>
#include <stdio.h> 


// void badmath_init(void);
// short badmath_factorial(int n);
// void badmath_cleanup(void);

// static long long getTimeInMs(void);
// static void sleepForMs(long long delayInMs);
void runCommand(char* command);
#endif