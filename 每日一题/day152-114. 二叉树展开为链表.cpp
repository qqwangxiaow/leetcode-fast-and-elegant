/**
 flatten left and right ,then concave
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)
            return;
        if(root->left)
            flatten(root->left);
        if(root->right)
            flatten(root->right);
        TreeNode *tmp=root->right;
        root->right=root->left;
        root->left=NULL;
        while(root->right)
        {
            root=root->right;
        }
        root->right=tmp;
    }
};