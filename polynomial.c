#include<stdio.h>

int main()
{
	int d1,d2,k;
	scanf("%d",&d1);
	scanf("%d",&d2);

	int A[d1],B[d2];

	if(d1>=d2)
		k = d1;
	else
		k= d2;

	for(int i=0;i<d1;i++)
		scanf("%d ",&A[i]);
	for(int i=0;i<d2;i++)
		scanf("%d ",&B[i]);

	int i=0,j=0,C[k];
	while(i<d1)
	{
			C[i] = A[i];
			i++;
	}
	while(j<d2)
	{
			C[j] += B[j];
			j++;
	}

	for(int i =0; i<k;i++)
		printf("%dx^%d + ",C[i],i);
}