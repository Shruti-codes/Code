#include<stdio.h>
int seq(int, int);

int main()
{
	int T, n, m;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d %d", &m, &n);

		printf("%d \n", seq(m,n));

	}
}

int seq(int m, int n)
{
	int num;
	if(m<n)
		return 0;
	if(n==0)
		return 1;

	num = seq(m/2 , n-1) + seq(m-1, n);
	return num;
}