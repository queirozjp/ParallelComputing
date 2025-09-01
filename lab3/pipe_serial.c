#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100000000

int main (){
    int *vector = (int *)malloc(SIZE * sizeof(int));
    for (int i = 0; i < SIZE; i++){
        vector[i] = i + 1;
    }
    long long sum = 0;
    struct timespec start , end;
    clock_gettime ( CLOCK_MONOTONIC , & start );
    for (int i = 0; i < SIZE; i++){
        sum = sum + vector[i];
    }
    clock_gettime ( CLOCK_MONOTONIC , &end);
    double time_spent = ( end. tv_sec - start . tv_sec ) + (end. tv_nsec - start . tv_nsec ) / 1e9;
    printf (" Versao serial executou em %f segundos \n", time_spent );
    printf("Soma: %lld\n", sum);

    return 0;
}