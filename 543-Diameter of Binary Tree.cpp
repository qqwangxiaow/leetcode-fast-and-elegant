/*最长diameter不一定通过root*/
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int l=diameterOfBinaryTree(root->left);
        int r=diameterOfBinaryTree(root->right);
        return max(getheight(root->right)+getheight(root->left),max(l,r));
        
    }
    int getheight(TreeNode *root)
    {
        if(!root)
            return 0;
        return max(getheight(root->left),getheight(root->right))+1;
        
    }
};