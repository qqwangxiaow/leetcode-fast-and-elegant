//1.when find a target,pop_back()
//2.pop_back() when dfs left and right
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root)
            return {};
        helper(root,sum);
        return ret;
    }
    void helper(TreeNode *root,int sum)
    {
        temp.push_back(root->val);
        if(!root->left&&!root->right&&sum==root->val)
        {
            ret.push_back(temp);
            temp.pop_back();
            return;
        }
        sum-=root->val;
        if(root->left)
            helper(root->left,sum);
        if(root->right)
            helper(root->right,sum);
        temp.pop_back();
    }
private:
    vector<vector<int>>ret;
    vector<int>temp;
};