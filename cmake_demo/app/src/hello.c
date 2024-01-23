// Main program to build the application
// Has main(); does initialization and cleanup and perhaps some basic logic.

#include <stdio.h>
#include <stdbool.h>
#include "timer.h"
#include "hal/button.h"

#define LEFT "config-pin p8.18 gpio"
#define RIGHT "config-pin p8.15 gpio"
#define UP "config-pin p8.14 gpio"
#define DOWN "config-pin p8.17 gpio"

enum direction {left = 1, right = 2, up = 3, down = 4, neutral = 0};

int main()
{
    printf("Hello embedded world, from Danieva!\nWhen the LEDs light up, press the joystick in that direction!\n");
    printf("Press left or right to exit\n");
    printf("Get ready...\n");


    // initialize
    runCommand(LEFT);
    runCommand(RIGHT);
    runCommand(UP);
    runCommand(DOWN);

    // readFromFileToScreen()

    // printf("Hello world!\n");

    // // Initialize all modules; HAL modules first
    // button_init();
    // badmath_init();

    // // Main program logic:
    // for (int i = 0; i < 10; i++) {
    //     printf("  -> Reading button time %d = %d\n", i, button_is_button_pressed());
    // }

    // for (int i = 0; i <= 35; i++) {
    //     int ans = badmath_factorial(i);
    //     printf("%4d! = %6d\n", i, ans);
    // }

    // // Cleanup all modules (HAL modules last)
    // badmath_cleanup();
    // button_cleanup();

    // printf("!!! DONE !!!\n"); 

    // Some bad code to try out and see what shows up.
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