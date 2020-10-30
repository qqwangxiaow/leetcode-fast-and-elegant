//if !root return 0
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return helper(root,0);
    }
    int helper(TreeNode *root,int sum)
    {
        if(!root)
            return 0;
        if(!root->left&&!root->right)
            return sum*10+root->val;
        return helper(root->left,sum*10+root->val)+helper(root->right,sum*10+root->val);
    }

};