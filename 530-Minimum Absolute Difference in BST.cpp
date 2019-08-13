//inorder非递归
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        if(!root)
            return 0;
        stack<TreeNode*>s;
        int ret=INT_MAX;
        int flag=0;
        TreeNode *pre;
        while(root||!s.empty())
        {
            while(root)
            {
                s.push(root);
                root=root->left;
            }
            if(!s.empty())
            {
                root=s.top();
                s.pop();
                if(flag)
                {
                    if(root->val-pre->val<ret)
                        ret=root->val-pre->val;
                }
                pre=root;
                flag++;
                root=root->right;
            } 
        }
        return ret;
     
     
    }
};

//inorder
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        long mindiff=INT_MAX;
        TreeNode *prev=nullptr;
        find(root,prev,mindiff);
        return mindiff;
        
    }
    void find(TreeNode *node,TreeNode*&prev,long &mindiff)
    {
        if(node->left)
        {
            find(node->left,prev,mindiff);
        }
        if(prev!=nullptr)
        {
            mindiff=min(mindiff,(long)abs(node->val-prev->val));
        }
        prev=node;
        if(node->right)
        {
            find(node->right,prev,mindiff);
        }
    }
};