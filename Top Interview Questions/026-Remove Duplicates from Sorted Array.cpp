//save non duplicate array to front
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=0;
        for(int n:nums)
        {
            if(!l||n>nums[l-1])
                nums[l++]=n;
        }
        return l;
    }
};