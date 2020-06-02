#include <stdio.h>
int main(void)
{

	FILE *myfile = fopen("stats.csv", "w");
	fprintf(myfile, "Type, List Size, Sum, Time\n"); 
	srand(time(NULL));

	printf("Program started\n");

	int n = 0, j = 0, i = 0, k = 8;
	
	while (i < 10)
	{
		while (j < 10)
		{
			int A[k];
			n = sizeof(A)/4;
			generateInput(A, n);
			//printlist(A, n);
			serialTime(A, n, myfile);
			parallelSumTime(A, n, n, myfile);
			j++;
		}
		j = 0;
		i++;
		k*=2;
	}	

	fclose(myfile);

	printf("Program finished, refer to stats.csv\n");
	return 0;
}
