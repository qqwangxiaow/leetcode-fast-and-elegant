//easy
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.empty())
            return -1;
        int count=0,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            count+=nums[i];
        }
        for(int i=0;i<nums.size();sum+=nums[i++])
        {
            if(2*sum==count-nums[i])
                return i;
        }
        return -1;
        
    }
};