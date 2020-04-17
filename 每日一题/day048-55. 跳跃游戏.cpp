//find curmax
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty())
            return false;
        int curmax=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(curmax<i)
                return false;
            if(i+nums[i]>curmax)
                curmax=i+nums[i];
        }
        return true;
    }
};