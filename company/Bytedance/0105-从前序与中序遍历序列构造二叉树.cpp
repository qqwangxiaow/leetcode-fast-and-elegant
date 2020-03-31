//l+1,l+dis  ll,ll+dis-1
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
        
    }
    TreeNode* helper(vector<int>&pre,int l,int r,vector<int>&inorder,int ll,int rr)
    {
        if(ll>rr||l>r)
            return nullptr;
        auto f=find(inorder.begin()+ll,inorder.begin()+rr,pre[l]);
        int dis=f-inorder.begin()-ll;
        TreeNode *root=new TreeNode(pre[l]);
        root->left=helper(pre,l+1,l+dis,inorder,ll,ll+dis-1);
        root->right=helper(pre,l+dis+1,r,inorder,ll+dis+1,rr);
        return root;
    }
};