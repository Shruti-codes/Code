//bottom-up, O(n) time, O(1) space

#include<stdio.h>
#include <limits.h>
#define max(a,b) (a>b?a:b)

int maxProfit(int* prices, int pricesSize)
{

    if(pricesSize == 0)
        return 0;
    
    int eS=0, eB=INT_MIN, pB=0, pS=0;
    
    for(int i=0; i<pricesSize; i++)
    {
        pB = eB;
        eB = max(eB, pS-prices[i]);
        pS = eS;
        eS = max(eS, pB+prices[i]);
    }
    return eS;
}

int main()
{
    int prices[] = {1,2,4};
    int pricesSize = 3;
    printf("%d\n",maxProfit(prices, pricesSize) );
}