//dp[i][j] to find sum/2;  i means 0...i   j means sum
//dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]] if j>=nums[i-1]

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
        vector<vector<int>>dp(nums.size()+1,vector<int>(sum+1,0));
        for(int i=0;i<=nums.size();i++)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<=nums.size();i++)
        {
            for(int j=1;j<=sum;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j>=nums[i-1])
                    dp[i][j]=(dp[i][j]||dp[i-1][j-nums[i-1]]);
                
            }
        }
        return dp[nums.size()][sum];
    }
};
//using one vector
//from left to right means dp[i][j] = dp[i][j-nums[i-1]])
//form right to left means dp[i][j] = dp[i-1][j-nums[i-1]]

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