//只交换在0和n之间的数到相应的位置，用while一直换
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty())
            return 1;
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]>0&&nums[i]<=nums.size()&&nums[nums[i]-1]!=nums[i])
            {
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i+1)
                return i+1;
        }
        return nums.size()+1;
        
    }
};