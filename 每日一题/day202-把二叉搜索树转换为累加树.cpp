/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        rev_inorder(root,0);
        return root;
    }
    int rev_inorder(TreeNode *root,int val)
    {
        if(!root)
            return val;
        int right=rev_inorder(root->right,val);
        root->val+=right;
        return rev_inorder(root->left,root->val);
        
    }
  
};