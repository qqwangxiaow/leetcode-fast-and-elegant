/**
偷或者不偷用pair<int,int>表示
 */
class Solution {
public:
    int rob(TreeNode* root) {
        return max(helper(root).first,helper(root).second);
    }
    pair<int,int>helper(TreeNode *root)
    {
        if(!root)  
            return make_pair(0,0);
        pair<int,int>left=helper(root->left);
        pair<int,int>right=helper(root->right);
        pair<int,int>ret;
        ret.first=root->val+left.second+right.second;
        ret.second=max(left.first,left.second)+max(right.first,right.second);
        return ret;

    }
};