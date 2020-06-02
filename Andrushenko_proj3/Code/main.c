#include "mpi.h"
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

int randomlife();
void setarray(int A[][16], int size, int rank);
void printarray(int A[][16], int size, int rank);
int main(int argc, char *argv[])
{
	srand((unsigned int)time(NULL));
	int rank, size, i;
	MPI_Status status;

	int tSend = 0, tComm = 0, tRecv = 0;
	struct timeval t1, t2, t3, t4;

	int procs = 4;
	int rows = 16;

	int gol[16][16];
	setarray(gol, procs, rank);
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if (size < 2)
	{
		printf("Please run with two processes.\n");fflush(stdout);
		MPI_Finalize();
        	return 0;
    	}

/////////////////////////////////////////////////////////////
	if (rank == 1)
	{
	}
	if (rank == 0)
	{
		printf("rank = %d\n", rank);
		printarray(gol, procs, rank);
	}
	else
	{
		printf("rank = %d\n", rank);

	}
/////////////////////////////////////////////////////////////
        fflush(stdout);
    	MPI_Finalize();
    	return 0;
}

int randomlife()
{
	int i = 0;
	i = (int)((rand() % 2));
	return i;
}
/*
void sendData(int A[][16], int size, int rank)
{
	int i = rank * size;
	size = size*size;
	j = 0;
	size2 = (i + h) - 1;
	while (i <= size2)
	{
		while (j < size)
		{
			MPI_Send(A[i][j], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
			j++
		}
		j = 0;
		i++;
	}
}
*/
void setarray(int A[][16], int size, int rank)
{
	int h = size;
	size = size * size;
	int i = rank * h;
	int j = 0;
	int size2 = (i + h) - 1;
	while (i <= size2)
	{
		while (j < size)
		{
			A[i][j] = randomlife();
			j++;
		}
		j = 0;
		i++;
	}
}

void printarray(int A[][16], int size, int rank)
{
	size = size * size;
        int i = 0;
	int j = 0;
	while (i <= size)
	{
		while (j < size)
		{
			if (A[i][j] == 0)
			{
				printf("%d ", A[i][j]);
				//printf("- ");
			}
			else
			{
				printf("%d ", A[i][j]);
				//printf("x ");
			}
			j++;

		}
		printf("\n");
		j = 0;
		i++;

	}
}
