#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<vector< int >> mat{{3,3,1,1},{2,2,1,2},{1,1,1,2}}; 

	int m = mat.size(), n = mat[0].size();
	printf("%d %d \n",m, n );

	for(int i=0; i<n; i++)
	{
		std::vector<int> d;
		int c = i;
		for(int j=0; j<m; j++)
		{
			d.push_back(mat[j][c]);
			c+=1;

			if(c>=n)
				break;
		}

		sort(d.begin(), d.end());
		c = i;

		for(int j=0; j<m; j++)
		{
			mat[j][c] = d[j];
			c+=1;

			if(c>=n)
				break;
		}
	}


	for(int i=1; i<m; i++)
	{
		std::vector<int> d;
		int c = i;
		for(int j=0; j<n; j++)
		{
			d.push_back(mat[c][j]);
			c+=1;

			if(c>=m)
				break;
		}

		sort(d.begin(), d.end());
		c = i;

		for(int j=0; j<n; j++)
		{
			mat[c][j] = d[j];
			c+=1;

			if(c>=m)
				break;
		}
	}

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}

}