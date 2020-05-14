#include<iostream>

using namespace std;

int main()
{
	int n,i,mid,l,s,flag=0;
	cin>>n;
	int A[n];
	for(i=0;i<n;i++)
		cin>>A[i];

	s=0;
	l=n;
	while(s<=l)
	{
		mid = (s+l) / 2;

		if(A[mid] == 1 && A[mid-1] == 0)
		{
			cout<<mid;
			flag = 1;
			break;
		}
		else if(A[mid]==0 && A[mid-1]==0)
			s=mid+1;
		else
			l=mid;
	}

	if(flag==0)
		cout<<-1;

}