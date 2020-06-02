#include <stdio.h> //I included it here and the source.h to remove annoying warnings
int main(void)
{

	srand(time(NULL));
	int n = 0;
	int A[8] = {0, 1, 2, 3, 4, 5, 6, 7};
	n = sizeof(A)/4; //each int is 4 bytes thus we must divide by 4
	
	generateInput(A, n);
	printlist(A, n);
	
	
	int r1 = 0;
	r1 = serialSum(A, n);
	printf("The sum for the serial function is %d\n", r1);

	printf("----------------------------------------\n");

	r1 = parallelSumSimulator(A, n, n);
	printf("The sum for the parallel sum simulator is %d\n", r1);
	return 0;
}
