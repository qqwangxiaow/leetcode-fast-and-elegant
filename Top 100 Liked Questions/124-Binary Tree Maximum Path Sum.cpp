//for each node as root,find max path value.
//and update maxsum when inorder

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        maxpathdown(root);
        return maxsum;
    }
    int maxpathdown(TreeNode *root)
    {
        if(!root)
            return 0;
        int left=max(0,maxpathdown(root->left));
        int right=max(0,maxpathdown(root->right));
        maxsum=max(maxsum,root->val+left+right);
        return max(left,right)+root->val;
    }
private:
    int maxsum=INT_MIN;
};