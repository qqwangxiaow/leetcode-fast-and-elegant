class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret=INT_MIN;
        vector<int>dp(nums.size()+1,0);
        for(int i=1;i<=nums.size();i++)
        {
            dp[i]=max(dp[i-1]+nums[i-1],nums[i-1]);
            ret=max(ret,dp[i]);
        }
        return ret;
        
    }
};