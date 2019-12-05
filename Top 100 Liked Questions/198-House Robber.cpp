//dp[i]=max(dp[i-1],dp[i-2]+A[i])
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int pre1=0,pre2=0,ret=0;
        for(int i=0;i<n;i++)
        {
            ret=max(pre1,pre2+nums[i]);
            pre2=pre1;
            pre1=ret;
        }
        return ret;
    }
};