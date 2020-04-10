#include<stdio.h>
#include<stdbool.h>
#define MAX 100

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

int extractMax(int A[],int n)
{
	int m = A[0];
	A[0]=A[n-1];
	maxheapify(A,n-1,1);
	return m;
}

void increaseKey(int A[], int key,int i)
{
		A[i] = key;
		while(i>0 && A[i/2-1]<A[i])
		{
			swap(&A[i],&A[i/2-1]);
			i=i/2-1;
		}
}

void insert(int A[],int n,int k)
{
	n=n+1;
	A[n-1] = k;
	maxheapify(A,n,n-1);
}

void delete(int A[],int n, int k)
{
	increaseKey(A,99999,k);
	extractMax(A,n);
}

bool isHeap(int A[],int i,int n)
{
	if (i > (n - 2)/2) 
    return true; 
	int left = 2*i+1;
	int right = 2*i+2;
	int parent = i;
	i++;
 
    if(!A[left] || !A[right])
        return true;
    else if((A[left] && A[left] > A[parent]) || (A[right] && A[right] > A[parent]))
        return false;

  return (isHeap(A,left,n) && isHeap(A,right,n));
}

int main()
{
	int n;
	scanf("%d",&n);
	int A[MAX];
	for(int i=0; i<n ;i++)
		scanf("%d ",&A[i]);
	int x;
	//scanf("%d",&x);
	//insert(A,n,x);
	//build(A,n);
	isHeap(A,0,n-1)?printf("True \n"):printf("False \n");
	for(int i =0; i<n;i++)
		printf("%d ",A[i]);
	//delete(A,n,3);

	//printf("%d \n", extractMax(A,n+1));
	//increaseKey(A,7,3);
}