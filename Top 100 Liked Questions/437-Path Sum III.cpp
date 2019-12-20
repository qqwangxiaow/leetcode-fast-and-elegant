//DFS
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
        return pathroot(root,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
    int pathroot(TreeNode *root,int sum)
    {
        if(!root)
            return 0;
        return (root->val==sum)+pathroot(root->left,sum-root->val)+pathroot(root->right,sum-root->val);
    }
};