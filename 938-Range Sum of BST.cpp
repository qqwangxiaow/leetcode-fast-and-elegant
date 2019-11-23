//iterative solution using stack
//conside null ptr in stack
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        stack<TreeNode*>s;
        s.push(root);
        int ret=0;
        while(!s.empty())
        {
            TreeNode *temp=s.top();
            s.pop();
            if(!temp)
                continue;
            if(temp->val>L)
                s.push(temp->left);
            if(temp->val<R)
                s.push(temp->right);
            if(L<=temp->val&&temp->val<=R)
                ret+=temp->val;
        }    
        return ret;
    }
};