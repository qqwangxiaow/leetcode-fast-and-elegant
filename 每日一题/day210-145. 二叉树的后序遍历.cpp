//首先要熟悉前序遍历 根-左-右
//然后结果反过来就是 右-左-根
//遍历的时候把先右边节点压栈就是 左-右-根
/*
前序遍历长这样
        vector<int>ret;
        stack<TreeNode*>s;
        while(root||!s.empty())
        {
            if(root)
            {
                s.push(root);
                ret.push_back(root->val);
                root=root->left;
            }
            else
            {
                root=s.top();
                s.pop();
                root=root->right;
            }
        }
        reverse(ret.begin(),ret.end());
        return ret;

*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ret;
        stack<TreeNode*>s;
        while(root||!s.empty())
        {
            if(root)
            {
                s.push(root);
                ret.push_back(root->val);
                root=root->right;
            }
            else
            {
                root=s.top();
                s.pop();
                root=root->left;
            }
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};