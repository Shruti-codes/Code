#include<stdio.h>

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

void maxheapify(int A[],int n,int i)
{
	int l=2*i;
	int r=2*i+1;
	int largest=i;
	if(l<n && A[l]>A[i])
		largest = l;
	else
		largest=i;
	if(r<n && A[r]>A[largest])
		largest=r;
	if(largest!=i)
	{
		swap(&A[i],&A[largest]);
		maxheapify(A,n,largest);
	}

}

void build(int A[], int n)
{
	for(int i=n/2-1; i>=0; i--)
		maxheapify(A,n,i);
}


void heapsort(int A[], int n)
{
	build(A,n);
	for(int i=n-1; i>=0; i--)
	{
		swap(&A[i],&A[0]);
		maxheapify(A,i,0);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int A[n];
	for(int i=0; i<n ;i++)
		scanf("%d ",&A[i]);

	heapsort(A,n);

	for(int i =0; i<n;i++)
		printf("%d ",A[i]);
}	