//区分哪边进行了旋转 然后改进二分查找
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(nums[m]==target)
            {
                return m;
            }
            if(nums[m]>nums[r])
            {
                if(target<nums[m]&&target>=nums[l])
                {
                    r=m-1;
                }
                else
                {
                    l=m+1;
                }
                
            }
            else
            {
                if(nums[m]<target&&target<=nums[r])
                {
                    l=m+1;
                }
                else
                {
                    r=m-1;
                }
            }
        }
        return -1;
    }
};