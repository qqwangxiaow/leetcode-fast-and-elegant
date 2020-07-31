//jump as long as possible
class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i=max(i+1,nums[i]))
        {
            if(nums[i]==i)
                return i;
        }
        return -1;
    }
};