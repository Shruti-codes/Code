#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

struct BTNode* insert(struct BTNode * , int );
void inorder(struct BTNode * );
struct BTNode* delete(struct BTNode *,int);
void search(struct BTNode* , int );
struct BTNode** createQueue(int *, int *); 
void enqueue(struct BTNode **, int *, struct BTNode *); 
struct BTNode *dequeue(struct BTNode **, int *); 
int height_iter(struct BTNode *);
struct BTNode* FindMin(struct BTNode *);
bool isSameTree(struct BTNode*, struct BTNode*);
#define stack_size 50

struct BTNode
{
	int data;
	struct BTNode *left;
	struct BTNode *right;
};

struct BTNode * BTNew(int key)
{
	struct BTNode* temp = (struct BTNode*)malloc(sizeof(struct BTNode));
	temp->data = key;
	temp->left = temp->right = NULL;
	return temp;
};

struct stack
{
	int top;
	struct BTNode *items[stack_size];
};

void push(struct stack *s,struct BTNode *key)
{
	if(s->top < stack_size-1)
		s->items[++(s->top)] = key;
	else
		printf("Overflow \n");
}

struct BTNode* pop(struct stack *s)
{
	if(s->top == -1)
	{
		printf("Underflow\n");
		return NULL;
	}
	else
		return s->items[(s->top)--];
}

int isEmpty(struct stack *s)
{
	if(s->top == -1)
		return 1;
	return 0;
}

struct BTNode** createQueue(int *front, int *rear) 
{ 
    struct BTNode **queue = 
        (struct BTNode **)malloc(sizeof(struct BTNode*)*stack_size); 
  
    *front = *rear = 0; 
    return queue; 
} 
  
void enqueue(struct BTNode **queue, int *rear, struct BTNode *new_node) 
{ 
    queue[*rear] = new_node; 
    (*rear)++; 
} 
  
struct BTNode * dequeue(struct BTNode **queue, int *front) 
{ 
    (*front)++; 
    return queue[*front - 1]; 
}

int isEmptyQ(struct BTNode *q)
{
	if(q)
		return 0;
	else
		return 1;
}

int levelorder(struct BTNode *root)
{
	int rear, front;
	int m = root->data; 	//for finding max w/o recursion
    struct BTNode **q = createQueue(&front, &rear); 
    struct BTNode *temp = root;

	while(temp)
	{
		printf("%d ", temp->data);
		if(temp ->left)
			enqueue(q,&rear,temp->left);
		if(temp ->right)
			enqueue(q,&rear,temp->right);
		if(temp->data > m)
			m = temp->data;
		temp = dequeue(q,&front);		
	}
	return m;
}

void zigzag(struct BTNode *root)
{
	int rear, front;
	struct BTNode **q = createQueue(&front, &rear); 
    struct BTNode *temp = root;
    int sig=1;
	while(temp)
	{
		if(sig==-1)
		{
			printf("%d ", temp->data);	
		    if(temp ->left)
					enqueue(q,&rear,temp->left);
			if(temp ->right)
					enqueue(q,&rear,temp->right);
			temp = dequeue(q,&front);
		}
		else
		{
			printf("%d ", temp->data);	
			if(temp ->right)
				enqueue(q,&rear,temp->right);
			if(temp ->left)
				enqueue(q,&rear,temp->left);
			temp = dequeue(q,&front);
		}
		sig = sig*-1;
	}		
}

//level order traversal bottom up
void levelreverse(struct BTNode *root)		//error
{
	int rear, front;
	struct stack *s;
	s->top = -1;
	struct BTNode **q = createQueue(&front, &rear); 
    struct BTNode *temp = root;
    enqueue(q,&rear,root);
    struct BTNode* curr =NULL ;
    
	while(!isEmptyQ(*q))
	{
		root = dequeue(q,&front);
		push(s,root);
		if(root ->right)
			enqueue(q,&rear,root->right);
		if(root ->left)
			enqueue(q,&rear,root->left);
	}

	while(isEmpty(s) == 0)
	{
		root = pop(s);
		printf("%d ", curr->data );
	}
}

void inorder(struct BTNode *root)
{
	if(root!=NULL)
	{
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
	}
}

void inorder_iter(struct BTNode *root)
{
	struct stack *s;
	s->top = -1;

	if(root == NULL)
		printf("Error \n");
	struct BTNode* curr = root;

	while(!isEmpty(s) || curr)
	{
		if(curr)
		{
			push(s,curr);
			curr = curr->left;
		}
		else
		{
		curr = pop(s);
		printf("%d ", curr->data);
		curr = curr->right;
		}

	}
}

void preorder(struct BTNode *root)
{
	struct stack *s;
	s->top = -1;

	if(root == NULL)
		printf("Error \n");
	struct BTNode* curr = NULL;
	push(s,root);

	while(!isEmpty(s))
	{
		curr = pop(s);
		printf("%d ", curr->data);
		if(curr->right)
			push(s,curr->right);
		if(curr->left)
			push(s,curr->left);
	}
}

void postorder(struct BTNode *root)
{
	struct stack *s;
	s->top = -1;

	if(root == NULL)
		printf("Error \n");
	struct BTNode* curr = NULL;
	push(s,root);

	while(!isEmpty(s))
	{
		curr = pop(s);
		if(curr->right)
			push(s,curr->right);
		if(curr->left)
			push(s,curr->left);
		printf("%d ", curr->data);
	}
}

int maxim_recur(struct BTNode *root)
{
	int val, max = 0,left,right;
	if(root!=NULL)
	{
		val = root->data;
		left = maxim_recur(root->left);
		right = maxim_recur(root->right);

		if(left<right)
			max = right;
		else
			max = left;

		if(val>max)
			max = val;
	}
	return max;
}

int main()
{
	struct BTNode *root = BTNew(3);
	root->left = BTNew(9);
	//root->left->left = BTNew(20);
	root->right= BTNew(20);
	root->right->left = BTNew(15);
	root->right->right = BTNew(7);

	struct BTNode *p = BTNew(1);
	p->left = BTNew(2);

	struct BTNode *q = BTNew(1);
	q->right = BTNew(2);	

	//inorder(root);

	// int x;
	// scanf("%d", &x);
	// insert(root,x);
	// inorder(root);
	// delete(root,x);
	// printf("\n");
	// inorder(root);
	//search(root,45);
	//printf("\n");
	//preorder(root);
	//printf("\n");
	//inorder_iter(root);
	//printf("\n");
	//postorder(root);
	//deleteTree(root);
	//printf(" \n %d ",height_iter(root));
	//levelorder(root);
	//printf("\n");
	//levelreverse(root);
	//printf("\n %d \n",maxim_recur(root));
	//printf("%d \n", size(root) );
	//printf("\n %d \n", widthOfBinaryTree(root));
	//printf("\n%d \n", isSameTree(p,q));
	//zigzag(root);
	printf("%d", sumOfLeftLeaves(root));
}

struct BTNode* insert(struct BTNode* node, int key)
{
	if(node==NULL)
		return BTNew(key);

	else if(key<=node->data)
		node->left = insert(node->left , key);

	else
		node->right = insert(node->right, key);

	return node;
}

struct BTNode* delete(struct BTNode *root,int key)
{
	if(root==NULL)
		return root;
	else if(root->data>key)
		root->left=delete(root->left,key);
	else if(root->data < key)
		root->right=delete(root->right,key);
	else
	{
		if(root->left == NULL && root->right == NULL)
		{
			free(root);
			root=NULL;
		}

		else if(root->left == NULL)
		{
			struct BTNode *temp = root;
			root = root->right;
			free(temp);
		}
		else if(root->right == NULL)
		{
			struct BTNode *temp = root;
			root = root->left;
			free(temp);
		}
		else
		{
			struct BTNode *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = delete(root->right,temp->data);
		}
   }
   return root;
}

struct BTNode* FindMin(struct BTNode *root)
{
	if(root==NULL)
		return NULL;
	while(root->left!=NULL)
		root = root->left;
	return root;
}

void search_rec(struct BTNode* root, int key)
{
	if(root==NULL)
		printf(" \n Not Found\n");
	else if(root->data == key)
		printf(" \n Found \n");
	else if(root->data > key)
		search(root->left, key);
	else
		search(root->right, key);
}

void search(struct BTNode *root, int key)
{
	int flag = 0;
	if(root == NULL)
		printf("Error \n");
	while(root!=NULL)
	{
		if(key == root->data)
		{
			flag = 1;
			break;
		}
		else if(key < root->data)
			root = root->left;
		else
			root = root->right;
	}
	if(flag == 1)
		printf(" \n Found\n");
	else
		printf("\n Not Found \n");
}

int size_recur(struct BTNode *root)
{
	if(root == NULL)
		return 0;
	else
		return (size_recur(root->left) + 1 + size_recur(root->right));
}

int size(struct BTNode *root)
{
	struct BTNode *temp = root;
	int c = 0,rear,front;
	struct BTNode **q = createQueue(&front, &rear);
	if(root == NULL)
		return 0;
	while(temp)
	{
		c++;
		if(temp ->left)
			enqueue(q,&rear,temp->left);
		if(temp ->right)
			enqueue(q,&rear,temp->right);
		temp = dequeue(q,&front);
	}
	return c;
}

int deleteTree(struct BTNode *root)
{
	if(root == NULL)
		return 0;
	deleteTree(root->left);
	deleteTree(root->right);
	free(root);
	return 1;
}

int height(struct BTNode *root)
{
	int L,R;
	if(root == NULL)
		return 0;
	else
	{
		L = height(root->left);
		R = height(root->right);
	}
	if(L>R)
		return (1+L);
	else
		return (1+R);

}

int height_iter(struct BTNode *root)
{
	struct BTNode *temp = NULL;
	int h = 0,rear,front;
	struct BTNode **q = createQueue(&front, &rear);
	enqueue(q,&rear,root);
	enqueue(q,&rear,NULL);
	if(root == NULL)
		return 0;
	while(!isEmptyQ(*q))
	{
		temp = dequeue(q,&front);
		if(temp == NULL)
		{
			if(!isEmptyQ(*q))
				enqueue(q,&rear,NULL);
			h++;
		}
		else
		{
			if(temp ->left)
			enqueue(q,&rear,temp->left);
			if(temp ->right)
			enqueue(q,&rear,temp->right);
		}
	}
	
	return h;
}

void preorderIter(struct BTNode* root, int* count, int l)
{
    if(root) 
    {
        count[l]++;
        preorderIter(root->left, count, l+1);
        preorderIter(root->right, count, l+1);
    }
}

int widthOfBinaryTree(struct BTNode* root)
{
     if(root==NULL)
        return 0;
    
    int n = height(root);
    int count[n];
    
    for(int i=0; i<n; i++)
        count[i] = 0;
    
    preorderIter(root, count, 0);
    
    int max = -1;
    for (int i = 0; i < n; ++i)
    {
        if (max < count[i])
            max = count[i];
    }
   
    return max;
}

bool isSameTree(struct BTNode* p, struct BTNode* q)
{
	if(p==NULL && q==NULL)
        return true;
    else if(p!=NULL && q!=NULL)
    {
	    return ((p->data == q->data) &&
	    		isSameTree(p->left, q->left) &&
	    		isSameTree(p->right, q->right));
	
	}
    return false;
}

int sumOfLeftLeaves(struct BTNode* root) 
    {
        int sum = 0;
        
        if(!root)
            return 0;
        
        if(root->left && root->left->left == NULL && root->left->right == NULL)
            sum += root->left->data;
        
        sum += (sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right));
        return sum;
    }