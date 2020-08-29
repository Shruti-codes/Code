//pancake sorting

#include<stdio.h>

void flip(int [], int);

int main()
{
	int A[4] = {3,2,1,4};
	int n = 4;

	for(int i=n-1; i>=0; i--)
	{
		int x=findMax(A,i);
		flip(A,x);
		flip(A,i-1);
	}

	for(int j=0; j<n; j++)
		printf("%d ", A[j]);
}

int findMax(int A[], int n)
{
	int max=0;
	for(int j=0; j<n; j++)
		if(A[max]<A[j])
			max=j;

	return max;
}

void flip(int A[], int i)
{
	int temp, start = 0; 
    while (start < i) 
    { 
        temp = A[start]; 
        A[start] = A[i]; 
        A[i] = temp; 
        start++; 
        i--; 
    } 
}