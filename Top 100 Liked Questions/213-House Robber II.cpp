//=max(rob(0...n-2),rob(1...n-1))
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        return max(helper(nums,0,nums.size()-2),helper(nums,1,nums.size()-1));
    }
    int helper(vector<int>&nums,int start,int end)
    {
        int pre1=0,pre2=0,cur=0;
        for(int i=start;i<=end;i++)
        {
            cur=max(pre1,pre2+nums[i]);
            pre2=pre1;
            pre1=cur;
        }
        return cur;
    }
};