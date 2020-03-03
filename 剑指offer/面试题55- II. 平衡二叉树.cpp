class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        if(abs(getheight(root->left)-getheight(root->right))<=1)
            return isBalanced(root->left)&&isBalanced(root->right);
        else
            return false;
    }
    int getheight(TreeNode* root)
    {
        return root?max(getheight(root->left),getheight(root->right))+1:0;
    }
};