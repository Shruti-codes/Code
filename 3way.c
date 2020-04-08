#include<stdio.h>

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

void sort012(int A[], int n)
{
	int lo=0, mid=0, hi=n-1;
	while(mid<=hi)
	{
		switch(A[mid])
		{
			case 0: swap(&A[lo],&A[mid]);
					lo++;
					mid++;
					break;
			case 1: mid++;
					break;
			case 2: swap(&A[mid],&A[hi]);
					hi--;
					break;
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int A[n];
	for(int i = 0; i<n ;i++)
		scanf("%d ",&A[i]);

	sort012(A,n);

	for(int i =0; i<n;i++)
		printf("%d ",A[i]);
}