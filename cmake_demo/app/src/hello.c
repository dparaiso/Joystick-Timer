// Main program to build the application
// Has main(); does initialization and cleanup and perhaps some basic logic.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <time.h>
#include "commands.h"
#include "hal/joystick.h"
#include "hal/led.h"




int main()
{
    printf("Hello embedded world, from Danieva!\nWhen the LEDs light up, press the joystick in that direction!\n");
    printf("(Press left or right to exit)\n");

    // initialize
    joystick_init(); 
    led_init(); 
    long long bestTime = 5000;

    while(true){
        printf("Get ready...\n");
        long long flag = 0; 
        while(response() > 0){
            if(flag == 0){
                printf("Please let go of joystick\n");
                flag++;
            } 
        }
        sleepForMs(randomTime());
        int direction = chooseDirection();
        if(direction){
            printf("Press DOWN now!\n");
            ledWrite(LED3, "1");
        }else{
            printf("Press UP now!\n");
            ledWrite(LED0, "1");
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
        ledWrite(LED0, "0");
        ledWrite(LED3, "0");
        long long endTime = getTimeInMs();      
        long long trialTime = endTime - startTime; 
        if(checkResponse(direction, responseDirection)){
            if(trialTime < bestTime){
                bestTime = trialTime; 
                printf("New best time!\n");
            }
            for(int i = 0; i < 4; i++){
                long long seconds = 0;
                long nanoseconds = 75000000;
                struct timespec reqDelay = {seconds, nanoseconds};
                nanosleep(&reqDelay, (struct timespec *) NULL);
                if(i%2){
                    ledWrite(LED0, "0");
                    ledWrite(LED1, "0");
                    ledWrite(LED2, "0");
                    ledWrite(LED3, "0");
                }else{
                    ledWrite(LED0, "1");
                    ledWrite(LED1, "1");
                    ledWrite(LED2, "1");
                    ledWrite(LED3, "1");
                }
            }
            
            printf("Your reaction time was %lldms; best so far in game is %lld\n", trialTime, bestTime);
        }else{
            for(int i = 0; i < 20; i++){
                long long seconds = 0;
                long nanoseconds = 30000000;
                struct timespec reqDelay = {seconds, nanoseconds};
                nanosleep(&reqDelay, (struct timespec *) NULL);
                if(i%2){
                    ledWrite(LED0, "0");
                    ledWrite(LED1, "0");
                    ledWrite(LED2, "0");
                    ledWrite(LED3, "0");
                }else{
                    ledWrite(LED0, "1");
                    ledWrite(LED1, "1");
                    ledWrite(LED2, "1");
                    ledWrite(LED3, "1");
                }
            }
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