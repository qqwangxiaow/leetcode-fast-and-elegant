class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        vector<int>num1(nums.begin(),nums.end()-1);
        vector<int>num2(nums.begin()+1,nums.end());
        int ret=max(rob1(num1),rob1(num2));
        return ret;
    }
    int rob1(vector<int>& nums) {
        int ret=0;
        vector<int>dp(nums.size()+1,0);
        for(int i=1;i<=nums.size();i++)
        {
            if(i>1)
                dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
            else    
                dp[i]=nums[0];
        }
        return dp[nums.size()];

    }
};