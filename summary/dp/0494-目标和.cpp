//suma+sumb=sum
//suma-sumb=S
//suma=(sum+S)/2
//寻找suma的个数 用+
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        return (sum<S||(sum+S)&1)?0:subsetsum(nums,(sum+S)>>1);
    }
    int subsetsum(vector<int>&nums,int sum)
    {
        vector<int>dp(sum+1,0);
        dp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=sum;j>=nums[i];j--)
            {
                dp[j]+=dp[j-nums[i]];
            }
        }
        return dp.back();
    }
};