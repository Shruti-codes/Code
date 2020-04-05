#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define V 4
#define Q_size 100
bool isBipartite(int [][V], int );

struct queue
{
	int rear,front,size;
	int *arr;
};

void enqueue(struct queue *q,int s) 
{ 
    q->arr[q->rear] = s; 
    (q->rear)++; 
    q->size = q->size + 1;
}

int dequeue(struct queue *q) 
{ 
    (q->front)++;
    q->size = q->size - 1;
    return q->arr[q->front - 1];
}

int isEmptyQ(struct queue *q)
{
	return (q->size == 0);
} 

int main()
{
	int G[][V] = {{0, 1, 0, 1}, 
        {1, 0, 1, 0}, 
        {0, 1, 0, 1}, 
        {1, 0, 1, 0} 
    };

    if(isBipartite(G,0))
    	printf("is Bipartite \n");
    else
    	printf("Not Bipartite \n");
}

bool isBipartite(int G[][V], int s)
{
	int c[V];
	for(int i=0; i<V; i++)
		c[i] = -1;

	c[s] = 1;

	struct queue *q = (struct queue *)malloc(sizeof(struct queue)*Q_size);
	q->arr = (int *)malloc(sizeof(int)*Q_size);
	q->rear = q->front = q->size = 0;
	enqueue(q,s);

	while(!isEmptyQ(q))
	{
		int u = dequeue(q);
		if(G[u][u] == 1)
			return false;

		for(int v = 0; v<V; v++)
		{
			if(G[u][v] && c[v] == -1)
			{
				c[v] = 1-c[u];
				enqueue(q,v);
			}
			else if(G[u][v] && c[v] == c[u])
				return false;
		}
	}
	return true;
}

