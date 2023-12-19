/*Write a C program that creates „n‟ child processes using fork() system call and
also print the process id along with its parent‟s process id of every child process.*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int n;
    printf("Enter the number of child processes to be created: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        pid_t child_pid = fork();
        if (child_pid == 0) {
            printf("Child process ID: %d\n", getpid());
            printf("Parent process ID: %d\n", getppid());
            return 0; // child process ends here
        } else {
            printf("## Parent process ID: %d\n", getpid());
        }
    }
    return 0;
}