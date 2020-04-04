#include<stdio.h>
int fact(int);

int main()
{
	int n;
	scanf("%d",&n);
	int x;
	x=fact(n);
	printf("%d\n",x );
}
int f[100];

int fact(int n)
{
	if(n==0 || n==1)
		return 1;
	else if(f[n]!=0)
		return f[n];
	else
		return f[n] = (n*fact(n-1));
}