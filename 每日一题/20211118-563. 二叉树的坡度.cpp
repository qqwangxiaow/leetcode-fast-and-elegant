//把算sum 和 坡度结合在一个递归
class Solution {
public:
    int ret = 0;
    int findTilt(TreeNode* root) {
        dfs(root);
        return ret;
    }
    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        ret += fabs(left - right);
        return left + right + root->val;
    }
};