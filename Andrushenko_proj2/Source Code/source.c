#include "source.h"

void setarray(int A[], int size)
{
	int x = 0;
	while (x < size)
	{
		A[x] = x;
		x++;
	}
}

void mpisend(int rank, int x)
{
        if (rank == 1)
        {
                int dest = 0;
                MPI_Send(&x, 1, MPI_INT, dest, 0, MPI_COMM_WORLD);
               // printf("Rank=%d: sent the number %d to rank %d\n", rank, x, dest);
        }
}
void mpirecv(int rank)
{
        if (rank == 0)
        {
                int y = 0;
                MPI_Status status;
                MPI_Recv(&y, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
               // printf("Rank=%d received the number %d from rank %d\n", rank, y, status.MPI_SOURCE);
        }
}
