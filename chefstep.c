#include<stdio.h>

int main()
{
	int T, N;
	long int K;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %ld", &N, &K);
		int P[N];
		char O[N];
		int k=0;
		for(int i=0; i<N; i++)
		{
			scanf("%d", &P[i]);
		}

		for(int i=0; i<N; i++)
		{
			if(P[i]%K == 0)
				O[k++] = '1';
			else
				O[k++] = '0';
		}
			printf("%s\n", O);
	}
}