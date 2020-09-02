//dp[i][j]表示最优情况下A选择边界能够与B产生的最大差值
//i为什么从len-2开始是因为 j必须大于i 填表的话从右下脚开始
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int len=nums.size();
        if(len<=1)
            return true;
        vector<vector<int>>dp(len,vector<int>(len,0));
        for(int i=0;i<nums.size();i++)
        {
            dp[i][i]=nums[i];
        }
        for(int i=len-2;i>=0;i--)
        {
            for(int j=i+1;j<len;j++)
            {
                dp[i][j]=max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1]);
            }
        }
        return dp[0][len-1]>=0;
    }
};

//空间优化
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int len=nums.size();
        if(len<=1)
            return true;
        vector<int>dp(len);
        for(int i=0;i<nums.size();i++)
        {
            dp[i]=nums[i];
        }
        for(int i=len-2;i>=0;i--)
        {
            for(int j=i+1;j<len;j++)
            {
                dp[j]=max(nums[i]-dp[j],nums[j]-dp[j-1]);
            }
        }
        return dp[len-1]>=0;
    }
};