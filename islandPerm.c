#include<stdio.h>

int findNeighbour(int, int, int [][4], int, int);

int islandPerimeter(int grid[][4], int gridSize, int gridColSize)
{
    int perm = 0;
    for(int i=0; i<gridSize; i++)
    {
        for(int j=0; j<gridColSize; j++)
            if(grid[i][j] == 1)
                perm += (4-findNeighbour(gridSize, gridColSize, grid, i, j));
    }
    return perm;
}

int findNeighbour(int gridSize, int gridColSize, int grid[][4], int i, int j)
{
    int co=0;
    if(i>0 && grid[i-1][j]==1)
        co++;
    if(i<gridSize-1 && grid[i+1][j]==1)
        co++;
    if(j<gridColSize-1 && grid[i][j+1])
        co++;
    if(j>0 && grid[i][j-1])
        co++;
    
    return co;
}

int main()
{
    int grid[4][4] ={0,1,0,0,
                     1,1,1,0,
                     0,1,0,0,
                     1,1,0,0};

    printf("%d \n", islandPerimeter(grid,4,4));
}