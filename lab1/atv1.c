#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <math.h>

int main(){
    pid_t pid = fork();
    if (pid < 0){
        printf("Fork falhou!");
    }else if (pid == 0){
        printf("Eu sou o filho.\n");
    }else{
        printf("Eu sou o pai.\n");
        wait(NULL);
        printf("Filho terminou\n");
    }
    
    return 0;
}