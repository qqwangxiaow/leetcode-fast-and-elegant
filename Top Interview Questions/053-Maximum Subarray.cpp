//dp[i]转换为必须以i结尾
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
            if(!i)
                dp[i]=nums[i];
            else
                dp[i]=dp[i-1]>0?nums[i]+dp[i-1]:nums[i];
        }
        return *max_element(dp.begin(),dp.end());
           
    }
};
