#include<stdio.h>
#include<stdbool.h>

int main()
{
	int m = 2, n = 3;
	int mat[2][3] = {{1,2,3}, {4,5,6}};
	bool path[2][3] = {{false}};
	printpath(mat,0,0,m,n,path);		//from starting point (0,0)

}

int printpath(int mat[][3],int i,int j,int m, int n, bool path[][3])		//i=current row, j=current column
{
	if(i<0 || i>m || j<0 || j>n || path[i][j])
		return 0;
	path[i][j] = true;

	if(i==m-1 && j==n-1)
	{
		for(int i = 0; i<m; i++)
		{
			for(int j=0;j<n;j++)
			{
				if(path[i][j])
				{
					printf("%d ", mat[i][j]);
				}
			}
		}
		printf("\n");
	}
	printpath(mat,i,j+1,m,n,path);
	printpath(mat,i+1,j,m,n,path);
	path[i][j] = false;
}