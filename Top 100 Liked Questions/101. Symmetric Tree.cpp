//recrusive
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return ismirror(root->left,root->right);
    }
    bool ismirror(TreeNode *root1,TreeNode *root2)
    {
        if(!root1||!root2)
            return root1==root2;
        if(root1->val!=root2->val)
            return false;
        else 
            return ismirror(root1->left,root2->right)&&ismirror(root1->right,root2->left);
        return true;
    }
};

