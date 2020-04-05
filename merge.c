#include<stdio.h>
void  merge(int [], int , int , int );
void mergesort(int [], int , int );

int main()
{
	int n;
	scanf("%d",&n);
	int A[n];
	for(int i = 0; i<n ;i++)
		scanf("%d ",&A[i]);

	mergesort(A,0,n-1);

	for(int i =0; i<n;i++)
		printf("%d ",A[i]);
}

void mergesort(int A[], int l, int r)
{
	if(l<r)
	{
		int mid = (l+r)/2;
		mergesort(A,l,mid);
		mergesort(A,mid+1,r);
		merge(A,l,mid,r);
	}
}

void  merge(int A[], int l, int m, int r)
{
	int n1=m-l+1;
	int n2=r-m;
	int L[n1], R[n2];
	for(int i=0; i<n1; i++)
		L[i] = A[l+i];
	for(int i=0; i<n2; i++)
		R[i] = A[m+1+i];

	L[n1] = 9999;
	R[n1] = 9999;
	int i,j,k;
	i=j=0;
	k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		A[k] = L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		A[k] = R[j];
		j++;
		k++;
	}
}