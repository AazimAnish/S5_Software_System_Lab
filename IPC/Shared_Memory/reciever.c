/*Write a program to implement IPC using shared memory*/

//read

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>
#include<sys/shm.h>

int main(){
    void*sharedmemory;
    char buff[100];
    int shmid;
    shmid=shmget((key_t)1122,1024,0666);
    printf("Key of the shared memory: %d\n",shmid);
    sharedmemory = shmat(shmid,NULL,0);
    printf("Address of the shared memory: %p\n",sharedmemory);
    printf("The data read from the shared memory: %s\n",(char*)sharedmemory);
    return 0;
}