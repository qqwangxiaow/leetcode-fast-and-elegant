/*递归*/
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL&&t2==NULL)
            return NULL;
        if(t1!=NULL&&t2==NULL)
            return t1;
        if(t1==NULL&&t2!=NULL)
            return t2;
        else 
        {
            t1->val+=t2->val;
            t1->left=mergeTrees(t1->left,t2->left);
            t1->right=mergeTrees(t1->right,t2->right);
            return t1;
        }
        
    }
};
/*more concise*/
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if ( t1 && t2 ) {
            TreeNode * root = new TreeNode(t1->val + t2->val);
            root->left = mergeTrees(t1->left, t2->left);
            root->right = mergeTrees(t1->right, t2->right);
            return root;
        } else {
            return t1 ? t1 : t2;
        }
        
    }
};