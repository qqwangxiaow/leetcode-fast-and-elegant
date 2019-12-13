//two state represent no rob and rob
//first no-robbed second robbed
class Solution {
public:
    int rob(TreeNode* root) {
        pair<int,int>ret=helper(root);
        return max(ret.first,ret.second);
    }
    pair<int,int> helper(TreeNode *root)
    {
        if(!root)
            return make_pair(0,0);
        pair<int,int>left=helper(root->left);
        pair<int,int>right=helper(root->right);
        pair<int,int>res;
        res.first=max(left.first,left.second)+max(right.first,right.second);
        res.second=left.first+right.first+root->val;
        return res;
    }

};

//using map to reduce subproblem
class Solution {
public:
    int rob(TreeNode* root) {
        return helper(root);
    }
    int helper(TreeNode *root)
    {
        if(!root)
            return 0;
        if(mymap.count(root))
            return mymap[root];
        int ret=0;
        if(root->left)
            ret+=helper(root->left->left)+helper(root->left->right);
        if(root->right)
            ret+=helper(root->right->left)+helper(root->right->right);
        ret=max(ret+root->val,helper(root->left)+helper(root->right));
        mymap.insert(make_pair(root,ret));
        return ret;
    }
private:
    map<TreeNode*,int>mymap;
};