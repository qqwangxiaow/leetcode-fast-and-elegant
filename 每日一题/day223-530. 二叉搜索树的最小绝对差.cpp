/**
pre要赋予nullptr
 */
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int ret=INT_MAX;
        stack<TreeNode*>s;
        TreeNode *pre=nullptr;
        while(root||!s.empty())
        {
            while(root)
            {
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            if(pre&&(root->val-pre->val)<ret)
            {
                ret=root->val-pre->val;
            }
            pre=root;
            root=root->right;
        }
        return ret;

    }
};