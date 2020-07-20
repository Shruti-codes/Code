#include<string.h>
#include<stdio.h>
#include<stdlib.h>

char * addBinary(char * a, char * b)
{

    int la, lb;
    la = strlen(a);
    lb = strlen(b);
    int i=la-1, j=lb-1, c=0, large;
    
    if(la>lb)
    	large = la;
    else
    	large = lb;

    char *s=(char*)malloc(sizeof(char)*(large+2));
    s[large+1] = '\0';
    int k = large;
    
   while( i>=0 || j >=0 || c ==1)
{
c += ((i>=0) ? a[i] - '0' :0 ); 
c += ((j>=0) ? b[j] - '0' :0 );

s[k--] = (c % 2) + '0';

c = c / 2;

--i;--j;
   }

   if(c==1)
   {
   	s[k] = '1';
       return s;
   }
    
    else
        return s+1+k; 
}

int main()
{
	printf("%s \n", addBinary("1","111"));
	return 0;
}