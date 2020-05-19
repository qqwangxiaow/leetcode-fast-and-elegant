class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ret=nums[0];
        int big=nums[0],small=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                swap(big,small);
            }
            big=max(nums[i],big*nums[i]);
            small=min(nums[i],small*nums[i]);
            ret=max(ret,big);
        }
        return ret;
    }
};