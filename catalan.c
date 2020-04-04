#include<stdio.h>

int func(int);

int main()
{
	int n,i;
	scanf("%d", &n);

	printf("%d \n",func(n));

}

int C[1024];

int func(int n)
{
	C[0] = 1;

	for(int i = 1; i<=n; i++)
		for(int j = 0; j<i; j++)
			C[i] += C[j]* C[i-j-1];
	return C[n];
}

	