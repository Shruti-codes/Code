#include<stdio.h>
#include<stdbool.h>

bool isPowerOfFour(long int num)
{
    long int co=0;
    
    if(num && !(num&(num-1)))
    {
        //count set bits
        while(num>1)
        {
            co+= 1;
            num=num>>1;
        }
        
         if(co%2==0)
            return true;
    }
    return false;
}

int main()
{
    printf("%d\n", isPowerOfFour(64));
    return 0;
}