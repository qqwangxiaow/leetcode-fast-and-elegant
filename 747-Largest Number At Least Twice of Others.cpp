//find max1 and max2，record index
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max1=0,max2=0;
        int index=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>max1)
            {
                max2=max1;
                max1=nums[i];
                index=i;
            }
            else if(nums[i]>max2)
            {
                max2=nums[i];
            }
        }
        return max1>=(max2<<1)?index:-1;
        
    }
};