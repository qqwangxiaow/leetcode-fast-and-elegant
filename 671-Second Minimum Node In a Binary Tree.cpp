//找最小值,与根结点不同则满足条件
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(!root)
            return -1;
        int ans=minval(root,root->val);
        return ans;    
    }
private:
    int minval(TreeNode *p,int first)
    {
        if(p==nullptr) return -1;
        if(p->val!=first) return p->val;
        int left=minval(p->left,first);
        int right=minval(p->right,first);
        if(left==-1) return right;
        if(right==-1) return left;
        return min(left,right);
    }
};