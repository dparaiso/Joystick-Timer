// Main program to build the application
// Has main(); does initialization and cleanup and perhaps some basic logic.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include "commands.h"
#include "hal/joystick.h"




int main()
{
    printf("Hello embedded world, from Danieva!\nWhen the LEDs light up, press the joystick in that direction!\n");
    printf("(Press left or right to exit)\n");

    // initialize
    joystick_init(); 
    long long bestTime = 5000;

    while(true){
        printf("Get ready...\n");
        long long i = 0; 
        while(response() > 0){
            if(i == 0){
                printf("Please let go of joystick\n");
                i++;
            } 
        }
        sleepForMs(randomTime());
        int direction = chooseDirection();
        if(direction){
            printf("Press DOWN now!\n");
        }else{
            printf("Press UP now!\n");
        }
        long long startTime = getTimeInMs(); 
        int responseDirection = response(); 
        while(responseDirection == 0){
            responseDirection = response();
            if(getTimeInMs()- startTime >= 5000){
                printf("No input within 5000ms; quitting!\n");
                exit(-1);
            }
        } 
        long long endTime = getTimeInMs();      
        long long trialTime = endTime - startTime; 
        if(checkResponse(direction, responseDirection)){
            if(trialTime < bestTime){
                bestTime = trialTime; 
                printf("New best time!\n");
            }
            printf("Your reaction time was %lldms; best so far in game is %lld\n", trialTime, bestTime);
        }
    }


    #if 0
        // Test your linting setup
        //   - You should see a warning underline in VS Code
        //   - You should see compile-time errors when building (-Wall -Werror)
        // (Linting using clang-tidy; see )
        int x = 0;
        if (x = 10) {
        }
    #endif
    #if 0
        // Demonstrate -fsanitize=address (enabled in the root CMakeFiles.txt)
        // Compile and run this code. Should see warning at compile time; error at runtime.
        int data[3];
        data[3] = 10;
        printf("Value: %d\n", data[3]);
    #endif
}