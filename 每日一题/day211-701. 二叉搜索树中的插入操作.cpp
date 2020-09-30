/*
非常优美的答案，!root的时候应该直接返回new TreeNode
不考虑旋转还是比较简单的 
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
        {
            return new TreeNode(val);
        }
        if(root->val<val)
        {
            root->right=insertIntoBST(root->right,val);
        }
        else 
        {
            root->left=insertIntoBST(root->left,val);
        }
        return root;
    }
};