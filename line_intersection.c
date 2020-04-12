#include<stdio.h>
#define MAX( a, b ) ( ( a > b) ? a : b )
#define MIN( a, b ) ( ( a < b) ? a : b )
int main()
{
	int p1[]={10,0},p2[]={0,10},p3[]={0,0},p4[]={10,10};
	
	if(intersect(p1,p2,p3,p4))
		printf("Intersecting\n");
	else
		printf("Not intersecting \n");

}

int intersect(int p1[], int p2[],int p3[], int p4[])
{
	int d1 = direction(p1,p2,p3);
	int d2 = direction(p1,p2,p4);
	int d3 = direction(p3,p4,p1);
	int d4 = direction(p3,p4,p2);

	if(((d1>0 && d2<0) || (d1<0 && d2>0)) && ((d3>0 && d4<0) || (d3<0 && d4>0)))
		return 1;
	else if(d1==0 && onsegment(p1,p2,p3))
		return 1;
	else if(d2==0 && onsegment(p1,p2,p4))
		return 1;
	else if(d3==0 && onsegment(p3,p4,p1))
		return 1;
	else if(d4==0 && onsegment(p3,p4,p2))
		return 1;
	else
		return 0;
}

int direction(int p[],int q[], int r[])
{
	return ((q[0]-p[0])*(r[1]-p[1]) - (r[0]-p[0])*(q[1]-p[1]));
}

int onsegment(int p[],int q[], int r[])
{
	if( (MIN(p[0],q[0])<=r[0] && r[0]<=MAX(p[0],q[0]))  && (MIN(p[1],q[1])<=r[1] && r[1]<=MAX(p[1],q[1])) )
		return 1;
	else
		return 0;
}