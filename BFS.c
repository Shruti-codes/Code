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

struct queue
{
	int *data, size;
	int rear, front;
};

void BFS(struct graph_list *G, int, int []);

void enqueue(struct queue *q,int x)
{
	if(!isFull(q))
	{
		q->rear += 1;
		q->data[q->rear] = x;
	}
}

int dequeue(struct queue *q)
{
	if(isEmpty(q))
	{
		printf("Underflow");
		return 0;
	}
	//free(q->data[q->front]);
	q->front += 1;
}

int isEmpty(struct queue *q)
{
	if(q->rear == q->front)
		return 1;
	return 0;
}

int isFull(struct  queue *q)
{
	if(q->front == q->rear+1)
		return 1;
	return 0;
}

int main()
{
			int temp, v,u;
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
			BFS(G,i,visited);
}

void BFS(struct graph_list *G, int u, int visited[])
{
	int v;
	struct queue *q = malloc(sizeof(struct queue));
	q->size = s;
	q->rear = q->front = -1;
	q->data = malloc(q->size * sizeof(int));

	enqueue(q,u);

	while(!isEmpty(q))
	{
		u = dequeue(q);
		printf("%d", u);
		visited[u] = 1;
		v = G->adj[u]->next;
		if(!visited[v] && G->adj[u])
		{
			enqueue(q,v);
			v = G->adj[u]->next;
		}	
	}
}
