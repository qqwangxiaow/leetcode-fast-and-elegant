//base dp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len=nums.size();
        vector<int>dp(len+1,0);
        for(int i=1;i<=nums.size();i++)
        {
            dp[i]=max(nums[i-1],dp[i-1]+nums[i-1]);
        }
        return *max_element(dp.begin()+1,dp.end());
    }
};

//no vector
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret=nums[0];
        int cur=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            cur=max(nums[i],cur+nums[i]);
            ret=max(cur,ret);
        }
        return ret;
    }
};