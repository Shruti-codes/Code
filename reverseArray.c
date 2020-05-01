#include<stdio.h>

int main()
{
	int T,n;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		int A[n], i, temp;

		for(i=0;i<n;i++)
			scanf("%d ", &A[i]);

		for(i=0;i<n/2;i++)
		{
			temp = A[i];
			A[i] = A[n-i-1];
			A[n-i-1] = temp;
		}
		
		for(i=0;i<n;i++)
			printf("%d ", A[i]);

		printf("\n");
	}

}