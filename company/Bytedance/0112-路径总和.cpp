//!root return false
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        if(!root->left&&!root->right)
        {
            if(root->val==sum)
                return true;
            else
                return false;
        }
        return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
    }
};