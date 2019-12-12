//dp[start][end]=maxsum for each k dp[start][k-1]+dp[k+1][end]+nums[start-1]*nums[k]*nums[end+1]
//bottom up
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),0));
        for(int len=1;len<=n;len++)
        {
            for(int start=1;start<=n-len+1;start++)
            {
                int end=start+len-1;
                for(int k=start;k<=end;k++)
                {
                    dp[start][end]=max(dp[start][end],dp[start][k-1]+dp[k+1][end]+nums[start-1]*nums[k]*nums[end+1]);
                }
            }
        }
        return dp[1][n];
    }
};