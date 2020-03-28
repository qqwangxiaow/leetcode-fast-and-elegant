//dp
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,0);
        for(int i=1;i<=nums.size();i++)
        {
            if(i==1)
                dp[i]=nums[i-1];
            else
                dp[i]=max(dp[i-2]+nums[i-1],dp[i-1]);

        }
        return dp[nums.size()];
    }
};