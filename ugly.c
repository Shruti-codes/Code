//ugly number = whose factors are prime nos 2, 3, 5 only

#include<stdio.h>
int min(int, int, int);

int nthUglyNumber(int n)
{
    int i2=0, i3=0, i5=0, k=0, f2=2, f3=3, f5=5;
    int list[n+1],m;
    list[0] = 1;
    while(k!=n)
    {
        m = min(f2,f3,f5);
        list[++k] = m;
        if(m == f2)
            f2 = 2*list[++i2];
        if(m == f3)
            f3 = 3*list[++i3];
        if(m == f5)
            f5 = 5*list[++i5];
    }
    return list[n-1];
}

int min(int a, int b, int c)
{
    if(a<=b && a<=c)
        return a;
    else if(b<=a && b<=c)
        return b;
    else
        return c;
}

int main()
{
    printf("%d \n", nthUglyNumber(10));
}