//find mid num
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        return helper(nums,l,r);
        
    }
    TreeNode* helper(vector<int>&nums,int l,int r)
    {
        if(l>r)
            return nullptr;
        int m=l+(r-l)/2;
        TreeNode* cur=new TreeNode(nums[m]);
        cur->left=helper(nums,l,m-1);
        cur->right=helper(nums,m+1,r);
        return cur;
    }
};