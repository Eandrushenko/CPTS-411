#include <stdio.h>
#include <mpi.h>
#include <assert.h>
#include <sys/time.h>


void setarray(int A[], int size);
void mpisend(int rank, int x);
void mpirecv(int rank);
