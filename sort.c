#include<stdio.h>
void bubble(int [], int );

int main()
{
	int n,i;
	scanf("%d",&n);
	int A[n];
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);

	bubble(A,n);
}

void bubble(int A[], int n)
{
	int i,j,temp,flag;
	for(i=0;i<n;i++)
	{
		flag = 0;
		for(j=0;j<i-1;j++)
		{
			if(A[j]>A[j+1] && flag == 0 )
			{
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
				flag = 1;
			}
		}
	}

	for(i=0;i<n;i++)
		printf("%d ", A[i]);
}