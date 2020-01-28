/*  a
   / \
  b   c
b + a + c。
b + a + a 的父结点。
a + c + a 的父结点
*/
//三种情况,第一种无法递归，但是可能是最大路径和，用sum保存，另外两种递归就是了
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ret=INT_MIN;
        maxPathdown(root,ret);
        return ret;
    }
    int maxPathdown(TreeNode* root,int &sum)
    {
        if(!root)
            return 0;
        int left=max(0,maxPathdown(root->left,sum));
        int right=max(0,maxPathdown(root->right,sum));
        sum=max(sum,left+right+root->val);
        return max(left,right)+root->val;
    }
};