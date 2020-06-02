/*	Cpt S 411, Introduction to Parallel Computing
 *	School of Electrical Engineering and Computer Science
 *	
 *	Example code
 *	Send receive test:
 *   	rank 1 sends to rank 0 (all other ranks sit idle)
 *   	For timing use of C gettimeofday() is recommended.
 * */


#include <stdio.h>
#include <mpi.h> 
#include <assert.h>
#include <sys/time.h>

int main(int argc,char *argv[])
{

	int rank,p;
	struct timeval t1,t2, t3, t4;

	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&p);

	//printf("my rank=%d\n",rank);
	//printf("Rank=%d: number of processes =%d\n",rank,p);

	assert(p >= 2);
	int x[262144]; //2^18
	setarray(x, (sizeof(x)/4));
	int tSend = 0, tRecv = 0, tComm = 0;

	int i = 0;
	int j = 1;
	printf("Size,Send Time, Communication Time, Receive Time\n");
	while (j <= 262144)
	{
		gettimeofday(&t3,NULL);
		gettimeofday(&t1,NULL);
		while (i < j)
		{
			mpisend(rank, x);
			i++;
		}
		gettimeofday(&t2,NULL);
		tSend = (t2.tv_sec-t1.tv_sec)*1000 + (t2.tv_usec-t1.tv_usec)/1000;
		i = 0;
		gettimeofday(&t1,NULL);
		while (i < j)
		{
			mpirecv(rank);
			i++;
		}
		gettimeofday(&t2,NULL);
		gettimeofday(&t4,NULL);
		tRecv = (t2.tv_sec-t1.tv_sec)*1000 + (t2.tv_usec-t1.tv_usec)/1000;
		tComm = (t4.tv_sec-t3.tv_sec)*1000 + (t4.tv_usec-t3.tv_usec)/1000;
		tComm = tComm - (tRecv + tSend);
		printf("%d,%d,%d,%d\n", j, tSend, tComm, tRecv);
		i = 0;
		j*=2;
	}
	MPI_Finalize();
}
