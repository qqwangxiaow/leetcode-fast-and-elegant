//&ret
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ret=0;
        getheight(root,ret);
        return ret;
    }
    int getheight(TreeNode *root,int &ret)
    {
        if(!root)
            return 0;
        int l=getheight(root->left,ret);
        int r=getheight(root->right,ret);
        ret=max(l+r,ret);
        return max(l,r)+1;

    }
};