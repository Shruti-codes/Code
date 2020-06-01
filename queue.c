#include<stdio.h>
#include<stdlib.h>
#define s 10

struct queue
{
	int *data, size;
	int rear, front;
};

int dequeue(struct queue *);
void enqueue(struct queue *,int );
int isEmpty(struct queue *);
int isFull(struct  queue *);

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
	free(q->data[q->front]);
	q->front += 1;
}

int main()
{
	struct queue *q = malloc(sizeof(struct queue));
	q->size = s;
	q->rear = q->front = -1;
	q->data = malloc(q->size * sizeof(int));

	enqueue(q,1);
	enqueue(q,2);
	dequeue(q);
	dequeue(q);
	printf("%d", q->data[q->front]);

	return 0;
}