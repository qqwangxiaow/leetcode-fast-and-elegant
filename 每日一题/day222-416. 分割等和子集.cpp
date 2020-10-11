//dp[i][j]表示0...i能组成j
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1)
            return false;
        int target=sum/2;
        vector<int>dp(target+1,0);
        dp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=target;j>=nums[i];j--)
            {
                dp[j]=dp[j]||dp[j-nums[i]];
            }
        }
        return dp.back();
    }
};