#include<queue>
#include<map>
#include<iterator>
#include<vector>
#include<iostream>
#include<set>
using namespace std;

struct BTNode
{
	int data;
	BTNode *left;
	BTNode *right;
};

BTNode* BTNew(int key)
{
	BTNode* temp = new BTNode ;
	temp->data = key;
	temp->left = temp->right = NULL;
	return temp;
};

void verticalOrder( BTNode* root);

int main()
{
	struct BTNode *root = BTNew(15);
	root->left = BTNew(9);
	root->left->left = BTNew(20);
	root->right= BTNew(20);
	root->right->left = BTNew(3);
	root->right->right = BTNew(7);

	verticalOrder(root);

}

void verticalOrder( BTNode* root)
{
	if(!root)
		exit(1);

	map<int, vector<int> > ord;
	int hd=0, node;

	queue<pair<BTNode*, int> > q;
	q.push(make_pair(root,hd));

	while(!q.empty())
	{
		map<int,set<int> > t;

		for(int i=0; i<q.size(); i++)
		{
			auto temp = q.front(); 
			q.pop();
			t[temp.second].insert(temp.first->data);

		if(temp.first->left)
			q.push(make_pair(temp.first->left, temp.second-1));
		if(temp.first->right)
			q.push(make_pair(temp.first->right, temp.second+1));
		
		}

	    for(auto x:t)
	    {
	        for(auto d:x.second)
	        {
	            ord[x.first].push_back(d);
	        }
	    }
	}

    vector<vector<int> > v;
	 for(auto it :ord)
        {
        	sort(it.second.begin(),it.second.end());
            v.push_back(it.second);
        }


    for (int i = 0; i < v.size(); i++)
    { 
        for (int j = 0; j < v[i].size(); j++) 
            cout << v[i][j] << " "; 
        cout << endl; 
    } 
}