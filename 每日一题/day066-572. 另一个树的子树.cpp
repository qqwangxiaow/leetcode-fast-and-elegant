/**
pay attention to !s
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s)
            return s==t;
        return isSameTree(s,t)||(isSubtree(s->left,t)||(isSubtree(s->right,t)));
    }
    bool isSameTree(TreeNode *t1,TreeNode *t2)
    {
        if(!t1&&!t2)
            return true;
        if(!t1||!t2)
            return false;
        if(t1->val!=t2->val)
            return false;
        else
            return isSameTree(t1->left,t2->left)&&isSameTree(t1->right,t2->right);
    }
};