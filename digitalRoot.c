#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	if(n==0)
		printf("0");
	else
		printf("%d\n", (1+ ((n-1)%9)) );
}