#include<stdio.h>
#define MAX 10
int main()
{
	 char  *contestants[] = {"john", "johnny", "jamie", "jackie" };
	 char *votes[] = { "john", "johnny", "jackie", 
                         "johnny", "john", "jackie", 
                         "jamie", "jamie", "john", 
                         "johnny", "jamie", "johnny", 
                         "john" }; 
	 int n = sizeof(contestants) / sizeof(contestants[0]);
	 int m = sizeof(votes) / sizeof(votes[0]);
	 int hash[n];



	 for(int i=0;i<n;i++)
	 hash[i] = 0;

	 for(int i=0;i<m;i++)
	 {
	 	if(votes[i]==contestants[0])
	 		hash[0]++;
	 	else if(votes[i]==contestants[1])
	 		hash[1]++;
	 	else if(votes[i]==contestants[2])
	 		hash[2]++;
	 	else if(votes[i]==contestants[3])
	 		hash[3]++;
	 }

	 int max = hash[0],ind=0;
	 for(int i=0;i<n;i++)
	 {
	 	if(hash[i]>m)
	 	{
	 		m=hash[i];
	 		ind = i;
	 	}
	 }

	 printf("%s \n",contestants[ind]);
}