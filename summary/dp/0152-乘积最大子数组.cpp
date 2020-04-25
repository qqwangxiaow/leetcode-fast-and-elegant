//big=max(nums[i],nums[i]*big)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int big=nums[0],small=nums[0],ret=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<0)
                swap(small,big);
            big=max(nums[i],nums[i]*big);
            small=min(nums[i],nums[i]*small);
            ret=max(ret,big);
        }
        return ret;
    }
};