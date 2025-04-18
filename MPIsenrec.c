#include<mpi.h>
#include<stdio.h>
#include<string.h>
const int MAX_STRING=100;
int main(void){
   char  greeting[MAX_STRING];
   int   comm_sz;
   int   my_rank;
   int i;
   
   MPI_Init(NULL, NULL);
   
   MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
   
   MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
   if(my_rank !=0)
   {
     sprintf(greeting, "Greetings from process %d of %d!",my_rank,comm_sz);
     
     MPI_Send(greeting, strlen(greeting)+1,MPI_CHAR, 0,0,MPI_COMM_WORLD);
   }
   else
   {
     printf("Greetings from process %d of %d!\n", my_rank, comm_sz);
     for(i=1;i<comm_sz;i++){
        MPI_Recv(greeting, MAX_STRING, MPI_CHAR,i,0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
     }
   }
   MPI_Finalize();
   return 0;
}
