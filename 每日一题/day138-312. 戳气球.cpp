class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),0));
        for(int len=1;len<=n;len++)
        {
            for(int start=1;start<=n-len+1;start++)
            {
                int end=start+len-1;
                for(int k=start;k<=end;k++)
                    dp[start][end]=max(dp[start][end],dp[start][k-1]+dp[k+1][end]+nums[k]*nums[start-1]*nums[end+1]);
            }

        }
        return dp[1][n];
    }
};