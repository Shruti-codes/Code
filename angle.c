#include<math.h>
#include<stdio.h>

double angleClock(int hour, int minutes)
{
    double res = 180.0-fabs(180.0 - fabs(6.0*minutes - (hour*30.0 + minutes*0.5)) );
    return res;
}

int main()
{
	printf("%lf \n", angleClock(3,15));
	return 0;
}