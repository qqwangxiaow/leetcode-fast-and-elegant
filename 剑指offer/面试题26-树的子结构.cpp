//if(!l2) not if(!l1&&!l2) because l1 don't need to be nullptr
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!B)
            return false;
        if(!A)
            return false;
        return istruefromroot(A,B)||isSubStructure(A->left,B)||isSubStructure(A->right,B);
    }
    bool istruefromroot(TreeNode *l1,TreeNode *l2)
    {
        if(!l2)
            return true;
        if(!l1||l1->val!=l2->val)
            return false;
        return istruefromroot(l1->left,l2->left)&&istruefromroot(l1->right,l2->right);
    }
};