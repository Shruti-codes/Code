#include<iostream>
#include<vector>
#define  d 50

int diameter[d];

using namespace std;

int main()
{
	int v,n;
	scanf("%d", &v);
	vector<int> A[v+1];

	for(int i=0; i<v; i++)
	{
		scanf("%d", &n);
		A[i].push_back(n);
	}
	cout<<dia(A,v);
}

void dia(vector<int> A[], int v)
{
	int s = bfs(1, A, v);
	int val = bfs(s, A, v);
	return diameter[val];
}

int bfs(int s, vector<int> A[], int v)
{
	queue<int> q;
	q.push(s);

	int visited[v+1];
	for(int i=0; i<=v; i++)
	{
		visited[i] = 0;
		diameter[i] = 0;
	}
	visited[s] = 1;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		for(int i=0; i<A[u].size(); i++)
		{
			if(visited[A[u][i]] == 0)
				visited[A[u][i]] == 1;

			diameter[A[u][i]] = diameter[u] + 1;
			q.push(A[u][i]);
		}
	}
	return int(max_element(diameter + 1, diameter + n + 1) - diameter); 
}

