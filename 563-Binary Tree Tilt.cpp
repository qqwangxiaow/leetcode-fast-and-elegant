/*postorder*/
class Solution {
public:
    int res=0;
    int findTilt(TreeNode* root) {
        dfs(root);
        return res;    
    }
    int dfs(TreeNode *root)
    {
        if(!root)
            return 0;
        int l=dfs(root->left);
        int r=dfs(root->right);
        res+=abs(l-r);
        return l+r+root->val;
    }
};