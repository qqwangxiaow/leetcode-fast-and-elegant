/**
same as inorder
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ret;
        stack<TreeNode*>stk;
        while(!stk.empty()||root)
        {
            while(root)
            {
                stk.push(root);
                ret.push_back(root->val);
                root=root->left;
            }
            root=stk.top();
            stk.pop();
            root=root->right;
        }
        return ret;
    }
};