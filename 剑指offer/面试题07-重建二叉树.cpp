//1.因为右边界是size() 所以l>=r||ll>=rr时候返回nullptr
//2.find(in.begin()+ll,in.begin()+rr,pre[l]) 这个也要改变
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,inorder,0,preorder.size(),0,inorder.size());
    }
    TreeNode* build(vector<int>&pre,vector<int>&in,int l,int r,int ll,int rr)
    {
        if(r<=l||rr<=ll)
            return nullptr;
        TreeNode *root=new TreeNode(pre[l]);
        auto f=find(in.begin()+ll,in.begin()+rr,pre[l]);
        int dis=f-in.begin()-ll;
        root->left=build(pre,in,l+1,l+dis+1,ll,ll+dis);
        root->right=build(pre,in,l+dis+1,r,ll+dis+1,rr);
        return root;
    }
};