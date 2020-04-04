#include<stdio.h>

void swap( int *, int * );
void Quicksort(int [], int , int );

int main()
{
	int n;
	scanf("%d",&n);
	int A[n];
	for(int i = 0; i<n ;i++)
		scanf("%d ",&A[i]);

	//Quicksort(A,0,n-1);
	printf(" \n %d",kthLargest(A,0,n-1,2));

	//for(int i =0; i<n;i++)
	//	printf("%d ",A[i]);

}

int kthLargest(int A[], int l, int r, int k)
{
	if(k>0 && k<=r-l+1)
	{
		int p = partition(A,l,r);
		if(p-1 == k)
			return A[p];
		else if(p-1>k-1)
			return kthLargest(A,l,p-1,k);
		else
			return kthLargest(A,p+1,r,k-p+l-1);
	}
}

void Quicksort(int A[],int l, int r)
{
	int p;
	if(l<r)
	{
	p = partition(A,l,r);
	Quicksort(A,l,p-1);
	Quicksort(A,p+1,r);
	}
}

int partition(int A[], int left, int right)
{
	int i = (left - 1);
	int p = A[right];
	for(int j = left; j<right; j++)
	{
		if(A[j] < p)
		{
			i++;
			swap(&A[i],&A[j]);
		}
	}
	swap(&A[i+1],p);
	return i+1;
}

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 