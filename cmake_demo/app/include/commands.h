// Sample application module
// Normally, you might create a module such as this for each module in
// the application that does some high-level task; perhaps has its own thread.

#ifndef _COMMANDS_H_
#define _COMMANDS_H_

long long getTimeInMs(void);
void sleepForMs(long long delayInMs);
long long randomTime();
int chooseDirection();
#endif