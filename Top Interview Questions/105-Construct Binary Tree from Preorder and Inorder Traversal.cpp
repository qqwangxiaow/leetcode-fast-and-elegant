//l>=r||ll>=rr
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,inorder,0,preorder.size(),0,inorder.size());
    }
    TreeNode* build(vector<int>&pre,vector<int>&in,int l,int r,int ll,int rr)
    {
        if(l>=r||ll>=rr)
            return NULL;
        TreeNode *root=new TreeNode(pre[l]);
        auto f=find(in.begin()+ll,in.begin()+rr,pre[l]);
        int dis=f-in.begin()-ll;
        root->left=build(pre,in,l+1,l+1+dis,ll,ll+dis);
        root->right=build(pre,in,l+1+dis,r,ll+dis+1,rr);
        return root;
    }
};