//inorder
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        inorder(root1);
        vector<int>v1=ret;
        ret.clear();
        inorder(root2);
        return v1==ret;
        
    }
    void inorder(TreeNode *root)
    {
        if(!root)
            return;
        inorder(root->left);
        if(!root->left&&!root->right)
        {
            ret.push_back(root->val);
        }
        inorder(root->right);
    }
private:
    vector<int>ret;
};