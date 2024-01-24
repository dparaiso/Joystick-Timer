#include "commands.h"
#include <stdio.h> 
#include <time.h> 
#include <stdlib.h>
#include <stdio.h> 

long long getTimeInMs(void)
{
    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    long long seconds = spec.tv_sec;
    long long nanoSeconds = spec.tv_nsec;
    long long milliSeconds = seconds * 1000 + nanoSeconds /1000000;
    return milliSeconds; 
}

void sleepForMs(long long delayInMs){
    const long long NS_PER_MS = 1000 * 1000; 
    const long long NS_PER_SECOND = 1000000000;
    
    long long delayNs = delayInMs * NS_PER_MS; 
    int seconds = delayNs / NS_PER_SECOND;
    int nanoseconds = delayNs % NS_PER_SECOND; 

    struct timespec reqDelay = {seconds, nanoseconds}; 
    nanosleep(&reqDelay, (struct timespec *) NULL);

}

// formula for random bounds from https://stackoverflow.com/questions/1202687/how-do-i-get-a-specific-range-of-numbers-from-rand
long long randomTime(){
    return rand() % (500 + 1 -  300) + 300;
}

int chooseDirection(){
    return rand()%2;
}
