#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    int i, n = 4;
    for (i = 0; i < n; i++){
        pid_t pid = fork();
        if (pid < 0){
            printf("Fork falhou.\n");
            return 1;
        } 
        else if (pid == 0){
            printf("Filho nº%d, pid: %d\n", i+1, getpid());
            return 0;
        }
    }
    for (i = 0; i < n; i++){
        wait(NULL);
    }
    printf("Todos os filhos foram terminados.\n");
    return 0;
}