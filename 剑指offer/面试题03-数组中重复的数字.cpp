//swap to suitable place 
//nums[i]==i
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]!=i)
            {
                if(nums[nums[i]]==nums[i])
                    return nums[i];
                else   
                    swap(nums[nums[i]],nums[i]);
            }
        }
        return 0;
    }
};