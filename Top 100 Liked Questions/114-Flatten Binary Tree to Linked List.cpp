//recrusive
class Solution {
public:
    void flatten(TreeNode* root) {
        flatten(root,NULL);   
    }
    TreeNode *flatten(TreeNode* root,TreeNode *pre)
    {
        if(!root)
            return pre;
        pre=flatten(root->right,pre);
        pre=flatten(root->left,pre);
        root->right=pre;
        root->left=NULL;
        pre=root;
        return pre;
    }

};
//NON-recrusive
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *now=root;
        while(now)
        {
            if(now->left)
            {
                TreeNode *pre=now->left;
                while(pre->right)
                {
                    pre=pre->right;
                }
                pre->right=now->right;
                now->right=now->left;
                now->left=NULL;
                
            }
            now=now->right;
        }
    }

};