/**
 * File includes joystick logic, initializing and checking joystick values
*/
#include "hal/joystick.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 


int readFromFileToScreen(char *fileName){
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

void runCommand(char* command){
    //Execute shell command (output into pipe)
    FILE *pipe = popen(command, "r");

    //Ignore output of the command; but consume it 
    //so we don't get an error when closing the pipe 
    char buffer[1024];
    while(!feof(pipe) && !ferror(pipe)){
        if(fgets(buffer, sizeof(buffer), pipe) == NULL)
        break; 
        // printf("--> %s", buffer); // uncomment for debugging
    }

    // get the exit code from the pipe; non-zero is an error: 
    int exitCode =  WEXITSTATUS(pclose(pipe));
    if (exitCode != 0){
        perror("Unable to execute command: ");
        printf("    command: %s\n", command); 
        printf("    exit code: %d\n", exitCode);
    }

}

void joystick_init(void) {
    runCommand(UP);
    runCommand(DOWN);
    runCommand(LEFT);
    runCommand(RIGHT);
}


int response(void){
    if(!readFromFileToScreen(UP_FILE)){
        return 1;
    }else if(!readFromFileToScreen(DOWN_FILE)){
        return 2;
    }else if(!readFromFileToScreen(LEFT_FILE)){
        return 3;
    }else if(!readFromFileToScreen(RIGHT_FILE)){
        return 4;
    }else{
        return 0;
    }

}

bool checkResponse(int targetDirection, int chosenDirection){
    if((targetDirection == 0 && chosenDirection == 1) || (targetDirection == 1 && chosenDirection == 2)){
        printf("Correct!\n");
        return true; 
    }else if(chosenDirection > 2){
        printf("User selected to quit.\n");
        exit(-1);
    }
    printf("Incorrect.\n");
    return false; 
}
