//getheight   diameter=getheight(l)+getheight(r)  because diameter!=nums of nodes
//global varable means max diameter is not only in root
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        findheight(root,diameter);
        return diameter;
    }
    int findheight(TreeNode* root,int &diameter)
    {
        if(!root)
            return 0;
        int l=findheight(root->left,diameter);
        int r=findheight(root->right,diameter);
        diameter=max(diameter,l+r);
        return 1+max(l,r); //height of parent
    }
};