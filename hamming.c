#include<stdio.h>
int hammingDistance(int,int);

int hammingDistance(int x, int y)
{
  	int c = x^y, co=0;
	
  	while(c)
  	{
  		co += c&1;
		c >>=1;  		
  	}
   	return co;
}

int main()
{
	printf("%d ", hammingDistance(1,4));
}