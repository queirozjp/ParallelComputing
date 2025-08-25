# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <time.h>
# include <math.h>

# define VECTOR_SIZE 200000000
# define NUM_PROCESSES 4

void heavy_work ( double * vector , int start , int end) {
	for (int i = start ; i < end ; ++i) {
		vector [i] = sin( vector [i]) * cos( vector [i]) + sqrt ( vector [i]);
	}
}

int main(){
    int chuncksize = VECTOR_SIZE/NUM_PROCESSES, i;
    int ini, fim;
    double * vector = ( double *) malloc ( VECTOR_SIZE * sizeof ( double ));
    for(int i = 0; i < VECTOR_SIZE ; i++) vector [i] = ( double )i;
    struct timespec start , end;
    clock_gettime ( CLOCK_MONOTONIC , & start );
    for (i = 0; i < NUM_PROCESSES; i++){
        pid_t pid = fork();
        if (pid < 0){
            printf("Fork falhou.\n");
            return 1;
        }
        else if(pid == 0){
            if (i == NUM_PROCESSES - 1){
                ini = i * chuncksize;
                fim = VECTOR_SIZE; 
            }else{
                ini = i * chuncksize;
                fim = (i+1) * chuncksize; 
            }
            heavy_work (vector , ini, fim );
            return 0;
        }

    }
    for (i = 0; i < NUM_PROCESSES; i++){
        wait(NULL);
    }
    clock_gettime ( CLOCK_MONOTONIC , &end);
    double time_spent = ( end. tv_sec - start . tv_sec ) + (end. tv_nsec - start . tv_nsec ) / 1e9;
    printf (" Versao sequencial executou em %f segundos \n", time_spent );
    return 0;
}