//maxpathdown
//return max(l,r)+root->val;
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ret=INT_MIN;
        maxPathDown(root,ret);
        return ret;
    }
    int maxPathDown(TreeNode *root,int &sum)
    {
        if(!root)
            return 0;
        int l=max(0,maxPathDown(root->left,sum));
        int r=max(0,maxPathDown(root->right,sum));
        sum=max(l+r+root->val,sum);
        return max(l,r)+root->val;
    }
};