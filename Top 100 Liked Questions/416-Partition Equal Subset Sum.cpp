//dp to find sum/2;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums)
        {
            sum+=num;
        }
        if(sum&1)
        {
            return false;
        }
        sum=sum/2;
        vector<int>dp(sum+1,false);
        dp[0]=true;
        for(int num:nums)
        {
            for(int i=sum;i>0;i--)
            {
                if(i>=num)
                    dp[i]=dp[i]||dp[i-num];
            }
        }
        return dp[sum];
    }
};