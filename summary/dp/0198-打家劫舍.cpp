class Solution {
public:
    int rob(vector<int>& nums) {
        int ret=0;
        vector<int>dp(nums.size()+1,0);
        for(int i=1;i<=nums.size();i++)
        {
            if(i>1)
                dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
            else    
                dp[i]=nums[0];
    
        }
        return dp[nums.size()];

    }
};