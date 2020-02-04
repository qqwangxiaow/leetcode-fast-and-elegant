//basic dp
//dp[i] means the maxlen at the end of i
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<int>dp(nums.size(),1);
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i]=max(dp[j]+1,dp[i]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};

//opt ret may not the LIS
//lower_bound >= 
//upper_bound >
//binary search in a sorted array
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ret;
        for(int i=0;i<nums.size();i++)
        {
            auto f=lower_bound(ret.begin(),ret.end(),nums[i]); //>=
            if(f==ret.end())
                ret.push_back(nums[i]);
            else
                *f=nums[i];
        }
        return ret.size();
    }
};
