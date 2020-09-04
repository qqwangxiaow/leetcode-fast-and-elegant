/**
backtrack
temp 保存路径 path
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ret;
        if(!root)
            return ret;
        helper(ret,to_string(root->val),root);
        return ret;

    }
    void helper(vector<string>&ret,string temp,TreeNode *root)
    {
        if(!root->left&&!root->right)
        {
            ret.push_back(temp);
        }
        if(root->left)
        {
            helper(ret,temp+"->"+to_string(root->left->val),root->left);
        }
        if(root->right)
        {
            helper(ret,temp+"->"+to_string(root->right->val),root->right);
        }
    }
};