//ismirror
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return ismirror(root,root);
    }
    bool ismirror(TreeNode *t1,TreeNode *t2)
    {
        if(!t1&&!t2)
            return true;
        if(!t1||!t2)
            return false;
        if(t1->val!=t2->val)
            return false;
        else
            return ismirror(t1->right,t2->left)&&ismirror(t1->left,t2->right);
    }
};