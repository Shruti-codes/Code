//rotate array in counter-clockwise direction

#include<stdio.h>

int main()
{
	int T,N,d;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		int A[N],temp;
		for(int i = 0; i<N; i++)
			scanf("%d", &A[i]);

		scanf("%d", &d);
		int B[d];

		for(int i=0; i<d; i++)
			B[i] = A[i];

		for(int i=d ,j=0; i<N; i++,j++)
			A[j]=A[i];

		for(int i = 0; i<d; i++)
			A[N-d+i] = B[i];

		for(int i = 0; i<N; i++)
			printf("%d ", A[i]);

		printf("\n");
	}
}
