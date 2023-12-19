/*Write a C program that shares a message between parent process and its child
process using pipe() system call*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

int main(){
    int pipe_fid[2];
    char message[] = "hello world!";

    pipe(pipe_fid);

    pid_t child = fork();


    if(child>0){
        close(pipe_fid[0]);
        write(pipe_fid[1],message,strlen(message )+1);
        close(pipe_fid[1]);
        
    }
    else{
       close(pipe_fid[1]);
       char readmessage[BUFFER_SIZE];
        read(pipe_fid[0],readmessage,BUFFER_SIZE);
        close(pipe_fid[0]);
       printf("child received: %s\n", readmessage );
    }
    return 0;
}