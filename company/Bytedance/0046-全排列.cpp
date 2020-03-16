class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ret;
        helper(ret,nums,0);
        return ret;

    }
    void helper(vector<vector<int>>&ret,vector<int>&nums,int start)
    {
        if(start==nums.size())
        {
            ret.push_back(nums);
            return;
        }
        for(int i=start;i<nums.size();i++)
        {
            swap(nums[start],nums[i]);
            helper(ret,nums,start+1);
            swap(nums[start],nums[i]);
        }

    }
};