#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 class Solution
 {
public:
    vector<vector<int> > levelOrderBottom(TreeNode* root)
    {
        vector<vector<int> > result;
        vector<int> level;
        queue<TreeNode*> myQueue;
        if(root == NULL)
            return result;
        myQueue.push(root);
        int currentLevelNodeNum = 1;//used to record num of nodes in current level
        int nextLevelNodeNum = 0;//used to record num of nodes in next level
        while(!myQueue.empty())
        {
            TreeNode* temp = myQueue.front();
            myQueue.pop();
            level.push_back(temp->val);
            currentLevelNodeNum--; 
            if(temp->left != NULL)
            {
                myQueue.push(temp->left);
            	nextLevelNodeNum++;
            }
            if(temp->right!= NULL)
            {
            	myQueue.push(temp->right);
            	nextLevelNodeNum++;
            }
            if(currentLevelNodeNum == 0)
            {//if we have traversed current level, turn to next level
            	result.push_back(level);//push the current level into result
        		level.clear();//clear level
        		currentLevelNodeNum = nextLevelNodeNum;//assign next level node num to current
        		nextLevelNodeNum = 0;//set next level num to 0
        	}
        }
        vector<vector<int> > final; //we have to reverse the order to get the final result
        for(int i = result.size()-1;i>=0;i--)
        {
        	final.push_back(result[i]);
        }
        return final;
    }
};

int main()
{
	struct TreeNode *root = TreeNode(50);
	root->left = TreeNode(30);
	root->left->left = BTNew(20);
	root->left->right = BTNew(40);
	root->right= BTNew(70);
	root->right->left = BTNew(60);
	Solution s;
	s.levelOrderBottom(root)
}