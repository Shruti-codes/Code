#include<stdio.h>

int main()
{
	int n,x;
	scanf("%d",&n);
	int A[n];
	for(int i = 0; i<n; i++)
		scanf("%d ",&A[i]);
	scanf("%d",&x);
	if(ter(A,0,n-1,x)!=-1)
		printf("Found \n");
	else
		printf("Not found \n");
}

int ter(int A[], int l, int r, int x)
{
	if(l<r)
	{
	int mid1 = l + (r-l)/2;
	int mid2 = mid1 + (r-l)/2;

	if(A[mid1]==x)
		return mid1;
	if(A[mid2]==x)
		return mid2;
	if(A[mid1]>x)
		return ter(A,l,mid1-1,x);
	if(A[mid2]<x)
		return ter(A,mid2+1,r,x);

	return ter(A,mid1+1,mid2-1,x);
}
return -1;
}