#include<stdio.h>

int main()
{
int n;
	scanf("%d",&n);
	int A[n];
	for(int i = 0; i<n ;i++)
		scanf("%d ",&A[i]);
	int x;
	scanf("%d",&x);

	if(calc(A,n,x))
		printf("Yes \n");
	else
		printf("No \n");
}

int calc(int A[], int n, int x)
{
	int l=0, r=n-1;
	while(l<r)
	{
		if(A[l]+A[r] == x)
			return 1;
		else if(A[l] + A[r] > x)
			r--;
		else
			l++;
	}
	return 0;
}
