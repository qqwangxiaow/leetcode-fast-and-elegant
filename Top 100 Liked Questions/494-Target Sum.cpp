/*                 sum(P) - sum(N) = target
sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
                       2 * sum(P) = target + sum(nums)

find sum(p)==(target+sum(nums))/2
like leetcode 416  but dp[i]+=dp[i-num]
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        return (sum<S||(S+sum)&1==1)?0:subsetsum(nums,(sum+S)>>1);
    }
    int subsetsum(vector<int>&nums,int sum)
    {
        vector<int>dp(sum+1,0);
        dp[0]=1;
        for(auto num:nums)
        {
            for(int j=sum;j>=num;j--)
            {
                dp[j]+=dp[j-num];
            }
                
        }
        return dp[sum];
        
    }
};
