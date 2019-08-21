/*写个函数判断当前root是否相等 然后递归判断*/
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s)
            return t==NULL;
        if(isSame(s,t))
            return true;
        return isSubtree(s->left,t)||isSubtree(s->right,t);
       
        
    }
    bool isSame(TreeNode *s,TreeNode *t)
    {
        if(!s&&!t)
            return true;
        if(!s||!t)
            return false;
        if(s->val!=t->val)
            return false;
        return isSame(s->left,t->left)&&isSame(s->right,t->right);
    }
};