#include "commands.h"


// static long long getTimeInMs(void)
// {
//     struct timespec spec;
//     clock_gettime(CLOCK_REALTIME, &spec);
//     long long seconds = spec.tv_sec;
//     long long nanoSeconds = spec.tv_nsec;
//     long long milliSeconds = seconds * 1000 + nanoSeconds /1000000;
//     return milliSeconds; 
// }

// static void sleepForMs(long long delayInMs)
// {
//     const long long NS_PER_MS = 1000 * 1000; 
//     const long long NS_PER_SECOND = 1000000000;
    
//     long long delayNs = delayInMs * NS_PER_MS; 
//     int seconds = delayNs / NS_PER_SECOND;
//     int nanoseconds = delayNs % NS_PER_SECOND; 

//     struct timespec reqDelay = {seconds, nanoseconds}; 
//     nanosleep(&reqDelay, (struct timespec *) NULL);

// }

void runCommand(char* command)
{
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

// void readFromFileToScreen(char fileName)
// {
//     FILEpFile = fopen(fileName, "r");
//     if (pFile == NULL) {
//     printf("ERROR: Unable to open file (%s) for read\n", fileName);
//     exit(-1);
//     }
//     // Read string (line)
//     const int MAX_LENGTH = 1024;
//     char buff[MAX_LENGTH];
//     fgets(buff, MAX_LENGTH, pFile);
//     // Close
//     fclose(pFile);
//     printf("Read: '%s'\n", buff);
// }

