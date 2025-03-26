#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>
#define NUM_NUMBERS 10000
int main(int argc, char *argv[]) {
    int rank, size;
    int numbers[NUM_NUMBERS];
    int local_min;
    int global_min;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    srand(time(NULL) + rank);
    if (rank == 0) {
        for (int i = 0; i < NUM_NUMBERS; i++) {
            numbers[i] = rand() % 10000; 
        }
    }
    int num_per_process = NUM_NUMBERS / size;
    int local_numbers[num_per_process];
    MPI_Scatter(numbers, num_per_process, MPI_INT, local_numbers, num_per_process, MPI_INT, 0, MPI_COMM_WORLD);
    local_min = local_numbers[0];
    for (int i = 0; i < num_per_process; i++) {
        if (local_numbers[i] < local_min) {
            local_min = local_numbers[i];
        }
    }
    MPI_Reduce(&local_min, &global_min, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        printf("Minimum value: %d\n", global_min);
    }
    MPI_Finalize();
    return 0;
}

