#include<stdio.h>
#include<stdlib.h>

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
	temp -> left = temp->right = NULL;
	return temp;
};

void mul(struct BTNode *root, int * );

int main()
{
	struct BTNode* root = BTNew(1); 
    root->left = BTNew(2); 
    root->left->left = BTNew(4); 
    root->left->right = BTNew(5); 
    root->right = BTNew(3); 
    root->right->right = BTNew(7); 
    root->right->left = BTNew(6); 
    root->right->left->right = BTNew(8);
	int p=1;
	mul(root,&p);
	printf("%d \n",p);

}

void mul(struct BTNode *root,int *p)
{
	if(!root)
		return;
	if((!root->left) && (!root->right))
		*p = (*p) * (root->data);
	
mul(root->left,p);
mul(root->right,p);
}