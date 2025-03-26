#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

#define N 1000

int main(int argc, char *argv[]) {
    int rank, size;
    int numbers[N];
    int local_min, local_max;
    int global_min, global_max;
    int elements_per_process;
    
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

   
    if (rank == 0) {
        srand(time(NULL)); 
        for (int i = 0; i < N; i++) {
            numbers[i] = rand() % 10000; 
        }
    }

    
    MPI_Bcast(numbers, N, MPI_INT, 0, MPI_COMM_WORLD);

    
    elements_per_process = N / size;

   
    local_min = numbers[rank * elements_per_process];
    local_max = numbers[rank * elements_per_process];

    for (int i = rank * elements_per_process; i < (rank + 1) * elements_per_process; i++) {
        if (numbers[i] < local_min) {
            local_min = numbers[i];
        }
        if (numbers[i] > local_max) {
            local_max = numbers[i];
        }
    }

 
    MPI_Reduce(&local_min, &global_min, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
    MPI_Reduce(&local_max, &global_max, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

    
    if (rank == 0) {
        printf("Global Min: %d\n", global_min);
        printf("Global Max: %d\n", global_max);
    }

    
    MPI_Finalize();
    return 0;
}
