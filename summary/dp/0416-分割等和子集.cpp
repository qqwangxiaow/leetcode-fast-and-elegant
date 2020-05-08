//这种是一维的情况
//dp[i][j]表示前i个元素能否组成j
//dp[i][j]=dp[i-1][j] 第i个不用
//dp[i][j]=dp[i-1][j-nums[i]] i用
//为什么要从后面？因为防止前面被重复利用
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto num:nums)
            sum+=num;
        if(sum%2==1)
            return false;
        sum/=2;
        vector<int>dp(sum+1,0);
        dp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=sum;j>=nums[i];j--)
            {
                dp[j]=dp[j]||dp[j-nums[i]];
            }   
        }
        return dp.back();
        
    }
};