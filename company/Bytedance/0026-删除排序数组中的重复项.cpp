//pay attention to empty()
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int l=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                nums[++l]=nums[i];
            }
        }
        return l+1;
    }
};