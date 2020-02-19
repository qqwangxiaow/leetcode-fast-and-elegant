class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root)
            return nullptr;
        TreeNode *left=mirrorTree(root->left);
        root->left=mirrorTree(root->right);
        root->right=left;
        return root;
    }
};