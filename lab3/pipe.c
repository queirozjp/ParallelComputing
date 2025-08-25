#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

#define SIZEOFVET 1000
#define FORKS 4

int main()
{
    int pipes[FORKS][2];
    for (int i = 0; i < FORKS; i++){
        pipe(pipes[i]);
        if (pipe(pipes[i]) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    }
    char vet[SIZEOFVET];
    pid_t pid;

    for(int i = 0; i < FORKS; i++){
        pid  = fork();
        if (pid < 0){
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if(pid == 0){
            close 
        }
    }
   return 0;
}