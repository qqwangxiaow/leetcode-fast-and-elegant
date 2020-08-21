/**
 必须是叶子节点
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left&&!root->right)
            return 1;
        if(!root->left)
            return minDepth(root->right)+1;
        if(!root->right)
            return minDepth(root->left)+1;
        return min(minDepth(root->left),minDepth(root->right))+1;
    }
};