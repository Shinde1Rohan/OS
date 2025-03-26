#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define ARRAY_SIZE 1000

int main(int argc, char** argv) {
    int my_rank, num_processes;
    int* array;
    int local_min = INT_MAX, global_min;
    int i;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_processes);

    srand(time(NULL) + my_rank);
    array = (int*) malloc(ARRAY_SIZE / num_processes * sizeof(int));
    for (i = 0; i < ARRAY_SIZE / num_processes; i++) {
        array[i] = rand() % 1000;
        if (array[i] < local_min) {
            local_min = array[i];
        }
    }

    MPI_Reduce(&local_min, &global_min, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
    if (my_rank == 0) {
        printf("The minimum number is %d\n", global_min);
    }
    free(array);
    MPI_Finalize();
    return 0;
}
