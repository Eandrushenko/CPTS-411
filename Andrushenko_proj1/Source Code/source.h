#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

void generateInput(int A[], int n);
void printlist(int A[], int n);
int serialSum(int A[], int n);
void copylist(int A[], int B[], int n);
int isPowerOfTwo(int n);
int parallelSumSimulator(int A[], int n, int p);
void serialTime(int A[], int n, FILE *myfile);
int parallelSumTime(int A[], int n, int p, FILE *myfile);
