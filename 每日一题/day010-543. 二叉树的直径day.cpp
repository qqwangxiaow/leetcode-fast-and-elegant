class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int left=diameterOfBinaryTree(root->left);
        int right=diameterOfBinaryTree(root->right);
        return max(getheight(root->left)+getheight(root->right),max(left,right));

    }
    int getheight(TreeNode *root)
    {
        if(!root)
            return 0;
        return max(getheight(root->left),getheight(root->right))+1;
    }
};
//more faster
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ret=0;
        gethegiht(root,ret);
        return ret;
    }
    int gethegiht(TreeNode *root,int &ret)
    {
        if(!root)
            return 0;
        int l=gethegiht(root->left,ret);
        int r=gethegiht(root->right,ret);
        ret=max(ret,l+r);
        return max(l,r)+1;
    }
};