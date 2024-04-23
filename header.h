#ifndef OSS_HEADER_FILE
#define OSS_HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <errno.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/time.h>
#include <stdbool.h>


#define maxProcesses 100
#define maxResources 20

typedef struct {
        long msg_type;    
        int pid;                
        int tableIndex;        
        int request;            
        int release;           
        bool terminate;         
        bool resourceGranted;  
        unsigned int messageTime[2];    
} Message;

/* Function Prototypes */
void handle ( int sig_num );    // Function to handle the alarm or ctrl-c signals

/* Message Queue Variables */
Message message;
int messageID;
key_t messageKey;

/* Shared Memory Variables */
int shmClockID;
int *shmClock;
key_t shmClockKey;

int shmBlockedID;
int *shmBlocked;
key_t shmBlockedKey;

#endif
