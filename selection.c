#include<stdio.h>
void swap(int *, int *);
int smallest(int [], int, int);

int main()
{
	int n,t;
	scanf("%d", &n);
	int A[n];
	for(int i=0; i<n; i++)
		scanf("%d", &A[i]);

	for(int i=0; i<n-1; i++)
	{
		int	min = smallest(A,i,n-1);
		t = A[i];
		A[i] = A[min];
		A[min] = t;
	}
	
	for(int i=0; i<n; i++)
		printf("%d ", A[i]);	

	return 0;
}

int smallest(int A[], int l, int r)
{
	int m = l;
	for(int j = l+1; j<r; j++)
	{
		if(A[j] < A[m])
		{
			m = j;
		}
	}
	return m;
}