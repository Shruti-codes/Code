#include <stdio.h>

int main() {
	int n, q, i, ind, co, T;
	scanf("%d", &T);
	while(T!=0)
	{
	scanf("%d", &n);
	int A[n], B[n];

	for(i=0; i<n; i++)
		scanf("%d", &A[i]);

	for(i=0; i<n; i++)
		scanf("%d", &B[i]);

	scanf("%d", &q);
    mergesort(B,0,n-1);
	while(q!=0)
	{
		scanf("%d", &ind);
		int a = A[ind], h=n-1, l=0;
		co=0;
		while(l<=h)
		{
		    int mid = (l+h)/2;
		    if(B[mid]<=a)
		    {
		        l = mid+1;
		        co = mid;
		    }
			else
			{
			    h = mid-1;
			}
		}
			if(co==0)
			printf("0\n");
			else
			printf("%d\n", co+1);
		q--;
	}
	T--;
	}
	return 0;
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

	L[n1] = 99999;
	R[n1] = 99999;
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