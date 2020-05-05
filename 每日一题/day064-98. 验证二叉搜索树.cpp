/**
minnode maxnode 
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root,nullptr,nullptr);
        
    }
    bool helper(TreeNode *root,TreeNode *minnode,TreeNode *maxnode)
    {
        if(!root)
            return true;
        if(minnode&&minnode->val>=root->val)
        {
            return false;
        }
        if(maxnode&&maxnode->val<=root->val)
        {
            return false;
        }
        return helper(root->left,minnode,root)&&helper(root->right,root,maxnode);

    }
};