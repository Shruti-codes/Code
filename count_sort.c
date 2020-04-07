#include<stdio.h>
#define RANGE 5

int main()
{
	int n;
	scanf("%d",&n);
	int A[n];
	for(int i = 0; i<n ;i++)
		scanf("%d ",&A[i]);

	int C[RANGE+1];
	int B[n];

	for(int i=0; A[i]; i++)
		C[A[i]] += 1;

	for(int i=1; i<=RANGE; i++)
		C[i] += C[i-1];

	for(int i =n-1; i>=0; i--)
			B[--C[A[i]]] = A[i];

	for(int i =0; i<n; i++)
		A[i] = B[i];

	for(int i =0; i<n;i++)
		printf("%d ",A[i]);
}