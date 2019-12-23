//把对应位置的数都标记为- 没有标记的地方对应的数就是缺少的数
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i]>0?nums[i]:-nums[i];
            if(nums[x-1]>0)
                nums[x-1]=-nums[x-1];
        }
        vector<int>ret;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                ret.push_back(i+1);
        }
        return ret;        
    }
};
