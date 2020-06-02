#include<stdio.h>
#include<stdlib.h>
#define s 20
//adjacency list
struct graph_list
{
	int V;
	int E;
	int *adj;
};

struct list
{
	int v;
	struct list *next;
};

void DFS(struct graph_list *G, int u, int visited[])
{
	printf("%d\n", u);
	visited[u] = 1;

	for(int v=0; v<G->V; v++)
	{
		v = G->adj[u]->next;
		if(!visited[v] && G->adj[u])
		{
			DFS(G,v,visited);
			v = G->adj[u]->next;
		}	
	}
}

int main()
{
	struct graph_list *G = (struct graph_list *)malloc(sizeof(struct graph_list));
	if(!G)
	{
		printf("Memory error\n");
		exit(1);
	}
	scanf("%d %d", &G->V, &G->E);
	G->adj = malloc(sizeof(struct list) * G->V);

	
	int visited[G->V];

	for(int i=0; i<G->V; i++)
		visited[i] = 0;

	for(int i=0; i<G->V; i++)
		if(!visited[i])
			DFS(G,i,visited);
}