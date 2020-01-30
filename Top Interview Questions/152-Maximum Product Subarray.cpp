//重点是考虑nums[i] 如果连nums[i]都比不过 那么抛弃前面的
//dp的想法是 big是以当前结点为末的最大子序列乘积 small是最小
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()<=0) return 0;
        int ret=nums[0];
        int big=nums[0],small=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<0)
                swap(big,small);
            big=max(nums[i]*big,nums[i]);
            small=min(nums[i]*small,nums[i]);
            ret=max(ret,big);
        } 
        return ret;  
    }
};