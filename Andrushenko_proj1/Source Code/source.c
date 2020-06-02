#include "source.h"

void generateInput(int A[], int n)
{
	int i = 0;
	int newnumber = 0;
	while (i < n)
	{
		A[i] = rand() % 100;
		i++;
	}
}

void printlist(int A[], int n)
{
	int i = 0;
	printf("[");
	while (i < n - 1)
	{
		printf("%d, ", A[i]);
		i++;
	}
	printf("%d]\n", A[i]);
}
	

int serialSum(int A[], int n)
{
	int i = 0;
	int sum = 0;
	while (i < n)
	{
		printf("running total = %d\n", sum);
		sum += A[i];
		i++;
	}
	return sum;
}

void copylist(int A[], int B[], int n)
{
	int i = 0;
	while( i < n)
	{
		A[i] = B[i];
		i++;
	}
}

//https://www.geeksforgeeks.org/program-to-find-whether-a-no-is-power-of-two/
int isPowerOfTwo(int n)
{
  if (n == 0)
    return 0;
  while (n != 1)
  {
      if (n%2 != 0)
         return 0;
      n = n/2;
  }
  return 1;
}

int parallelSumSimulator(int A[], int n, int p)
{
	if (n != p)
	{
		printf("ERROR : n != p\n");
		return;
	}
	if (!(isPowerOfTwo(n)))
	{
		printf("ERROR : n is not a power of 2\n");
		return;
	}
	int proc[p];
	copylist(proc, A,  p);

	int i = 0;
	int j = 2;
	int k = 0;

        while (j <= n)
        {
                printlist(proc, n);
                i = 0;
                k = j/2;
                while (i < n)
                {
                        proc[i] = proc[i] + proc[i + k];
                        i+=j;
                }
                j*=2;
        }
        printlist(proc, n);

	//Sum has been found at this point
	//now to share the answer with the other proccesses
	printf("returning sum to other proccesses\n");	
	i = 0;
	j = n;
	k = j/n;
	
	while (j >= 2)
	{
		printlist(proc, p);
		i = 0;
		k = j/2;
		while (i < n)
		{
			proc[i + k] = proc[i];
			i += j;
		}
		j/=2;
	}
	printlist(proc, p);
	return proc[0];
		
}

void serialTime(int A[], int n, FILE *myfile)
{
	int i = 0;
	int sum = 0;
	struct timeval start, end;
	gettimeofday(&start, NULL);
	while (i < n)
	{
		sum += A[i];
		i++;
	}
	gettimeofday(&end, NULL);
	fprintf(myfile, "Serial, %d, %d, ", n, sum);
	
	fprintf(myfile, "%ld\n", ((end.tv_sec * 1000000 + end.tv_usec)
		  - (start.tv_sec * 1000000 + start.tv_usec)));
}

int parallelSumTime(int A[], int n, int p, FILE *myfile)
{
	if (n != p)
	{
		printf("ERROR : n != p\n");
		return;
	}
        if (!(isPowerOfTwo(n)))
        {
                printf("ERROR : n is not a power of 2\n");
                return;
        }

	int proc[p];
	copylist(proc, A,  p);

	int i = 0;
	int j = 2;
	int k = 0;

	struct timeval start, end;
        gettimeofday(&start, NULL);


        while (j <= n)
        {
                i = 0;
                k = j/2;
                while (i < n)
                {
                        proc[i] = proc[i] + proc[i + k];
                        i+=j;
                }
                j*=2;
        }

	gettimeofday(&end, NULL);

	fprintf(myfile, "Parallel, %d, %d, ", n, proc[0]);
        fprintf(myfile, "%ld\n", ((end.tv_sec * 1000000 + end.tv_usec)
                  - (start.tv_sec * 1000000 + start.tv_usec)));

		
}

