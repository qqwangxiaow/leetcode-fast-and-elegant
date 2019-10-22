//same as 530   using stack no recursive
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int ret=INT_MAX,flag=0;
        TreeNode *pre;
        stack<TreeNode*>s;
        while(root||!s.empty())
        {
            while(root)
            {
                s.push(root);
                root=root->left;
            }
            if(!s.empty())
            {
                root=s.top();
                s.pop();
                if(flag)
                {
                    ret=min(ret,root->val-pre->val);
                }
                pre=root;
                flag++;
                root=root->right;
            }
        }
        return ret;
       
    }
       
};
//recrusive
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        if(root->left)
            minDiffInBST(root->left);
        if(pre)
        {
            ret=min(ret,root->val-pre->val);
        }
        pre=root;
        if(root->right)
            minDiffInBST(root->right);
        return ret;
    }
private:
    TreeNode *pre=nullptr;
    int ret=INT_MAX;
       
};