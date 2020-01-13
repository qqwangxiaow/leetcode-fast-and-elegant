//greedy optimize
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last=nums.size()-1;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]+i>=last)
            {
                last=i;
            }
        }
        return last==0;
    }
};
//greedy
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farest=0;
        for(int i=0;i<nums.size();i++)
        {
            if(farest<i)
                return false;
            else
                farest=max(farest,i+nums[i]);
        }
        return true;
    }
};
//dp time limit exceeded
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
        if(nums.size()==1)
            return true;
        dp[0]=1;
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[j]&&j+nums[j]>=i)
                {
                    dp[i]=1;
                }
            }
        }
        return dp[nums.size()-1];
    }
};