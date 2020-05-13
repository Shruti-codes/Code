#include<iostream>

using namespace std;

int main()
{
	int n,i,div;
	cin>>n;

	int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
	string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};

	i=12;
	while(n!=0)
	{
		div = n/num[i];
		n = n%num[i];
		
		while(div--)
		{
			cout<<sym[i];
		}
		i--;
	}
	return 0;
}