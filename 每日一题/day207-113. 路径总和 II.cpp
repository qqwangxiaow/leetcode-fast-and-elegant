/**
回溯
在叶子节点直接push_back
而不是等到空节点
空节点的话会有重复
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>ret;
        vector<int>temp;
        helper(ret,temp,root,sum);
        return ret;

    }
    void helper(vector<vector<int>>&ret,vector<int>&temp,TreeNode *root,int target)
    {
        if(!root)
            return;
        temp.push_back(root->val);
        if(root->val==target&&!root->left&&!root->right)
            ret.push_back(temp);
        helper(ret,temp,root->left,target-root->val);
        helper(ret,temp,root->right,target-root->val);
        temp.pop_back();

    }
};