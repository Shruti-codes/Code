#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}

struct queue
{
	struct node *rear;
	struct node *front;
}

struct stack
{
	struct node *top;
}

void push(struct stack *s, int x)
{
	struct node *temp = malloc(sizeof(struct node));
	if(!temp)
		return NULL;

	temp->data = x;
	temp->next = NULL;
	s->top = temp;
}

int pop(struct stack *s)
{
	struct node *temp;
	int x = 0;
	if(isEmptyStack(s))
	{
		printf("Underflow\n");
		return;
	}
	temp = s->top;
	x = s->top->data;
	s->top = s->top->next;
	free(temp);
	return x;
}

void enqueue(struct queue *q, int x)
{
	struct node *new = malloc(sizeof(struct node));
	if(!new)
		return NULL;

	new->data = x;
	new->next = NULL;
	if(q->rear)
		q->rear->next = new;
	q->rear = new;

	if(q->front == NULL)
		q->front = q->rear;
}

int isEmpty(struct queue *q)
{
	if(q->front == q->rear == NULL)
		return 1;
	return 0;
}

int isEmptyStack(struct stack *s)
{
	return (s->top == NULL);
}

int dequeue(struct queue *q)
{
	int x = 0;
	struct node *temp;
	if(isEmpty(q))
	{
		printf("Underflow\n");
		return -1;
	}
	temp = q->front;
	x = q->front->data;
	q->front = q->front->next;
	free(temp);

	return data;
}

void reverse(struct queue *q)
{
	struct stack *S = malloc(sizeof(struct stack));

	while(isEmpty(q))
		push(S, dequeue(q));
	while(!isEmptyStack(S))
		enqueue(q, pop(S));
}

int main()
{
	struct queue *q = malloc(sizeof(struct queue));

	q->front = q->rear = NULL;

	enqueue(q,1);
	enqueue(q,2);

	reverse(q);
}