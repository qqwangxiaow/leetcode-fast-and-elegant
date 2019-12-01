//DFS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        findheight(root,x,y,0,NULL);
        return heightx==heighty&&parentx!=parenty;
    }
    void findheight(TreeNode* root,int x,int y,int height,TreeNode *parent)
    {
        if(!root)
            return;
        if(root->val==x)
        {
            heightx=height;
            parentx=parent;
        }
        else if(root->val==y)
        {
            heighty=height;
            parenty=parent;
        }
        findheight(root->left,x,y,height+1,root);
        findheight(root->right,x,y,height+1,root);
    }
private:
    int heightx;
    int heighty;
    TreeNode *parentx;
    TreeNode *parenty;
};

//BFS
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root)
            return false;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            bool findx=false;
            bool findy=false;
            for(int i=0;i<n;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                if(temp->val==x)
                    findx=true;
                if(temp->val==y)
                    findy=true;
                if(temp->left&&temp->right)
                {
                    if(((temp->left->val)==x)&&((temp->right->val)==y))
                        return false;
                    if(((temp->left->val)==y)&&((temp->right->val)==x))
                        return false;
                }
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            if(findx&&findy)
                return true;
            else if(findx||findy)
                return false;
        }       
        return false;
    }

};