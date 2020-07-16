#include<stdio.h>

double myPow(double x, int n)
{
	double t;
    if(n==1)
        return x;
    if(n==-1)
    	return (1.0/x);
    t = myPow(x,n/2);
    if(n%2==0)
        return t*t;
    else
    {
    	if(n>0)
        	return x*t*t;
    	else
    		return (t*t)/x;

	}

}

int main()
{
	printf("%e \n", myPow(34.00515,-3));
	return 0;
}