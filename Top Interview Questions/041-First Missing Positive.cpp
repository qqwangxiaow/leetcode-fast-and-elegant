//swap to true place,such as 1--nums[0],2--nums[1]
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty())
            return 1;
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]>0&&nums[i]<nums.size()+1&&nums[i]!=nums[nums[i]-1])
            {
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i+1)
            {
                return i+1;
            }
        }
        return nums.size()+1;
    }
};