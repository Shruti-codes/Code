#include<stdio.h>

int main()
{
	int n,f,k;
	scanf("%d", &n);
	int A[n];
	
	for(int i=0; i<n; i++)
		scanf("%d", &A[i]);

	for(int i=1; i<n; i++)
	{
		f = A[i];
		k = i-1;
		while(k>=0 && A[k] >= f)
		{
			A[k+1] = A[k];
			k = k-1;
		}
		A[k+1] = f;
	}

	for(int i=0; i<n; i++)
		printf("%d  ", A[i]);	

	return 0;
}
