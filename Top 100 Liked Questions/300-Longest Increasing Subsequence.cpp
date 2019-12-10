//my dp solution
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<int>dp(nums.size(),1);
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                    dp[i]=max(dp[i],dp[j]+1);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
//lower_bound position >= , find in ret
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ret;
        for(int i=0;i<nums.size();i++)
        {
            auto it=lower_bound(ret.begin(),ret.end(),nums[i]);
            if(it==ret.end())
                ret.push_back(nums[i]);
            else
                *it=nums[i];
        }
        return ret.size();
    }
};