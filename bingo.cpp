#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector< vector< int> > mat{{0,0,0},{0,0,0},{0,0,0}};
	int co=0, ro=0, di1=0, di2 = 0,d=0;

	for(int i=0; i<mat.size(); i++)
	{
		for(int j=0; j<mat[0].size(); j++)
		{
			if(mat[i][j]==0)
			{
				co+=1;
			}
		}
		if(co==mat[0].size())
		{
			co=1;
			break;
		}
	}

	for(int i=0; i<mat[0].size(); i++)
	{
		for(int j=0; j<mat.size(); j++)
		{
			if(mat[i][j]==0)
			{
				ro+=1;
			}
		}
		if(ro==mat.size())
		{	
			d++;
			ro=0;
		}
	}

	if(ro==0)
		ro=1;

	for(int i=0; i<mat.size(); i++)
	{
			if(mat[i][i]==0)
			{
				di1+=1;
			}
	}
		if(di1==mat.size())
			di1=1;

	for(int i=0; i<mat.size(); i++)
	{
		for(int j=0; j<mat[0].size(); j++)
		{
			if((i+j) == (mat.size()-1) && mat[i][j]==0)
			{
				di2+=1;
			}
		}
		if(di2==mat.size())
			di2=1;
	}

// printf("%d \n", ro );
	if(co==1 && ro==1 && di1==1 && di2==1)
		printf("Bingo\n");
	else
		printf("Not Bingo\n");
}